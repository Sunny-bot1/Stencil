#include <stdio.h>
#include "cuda.h"
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))
#define ceil(a,b)   ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

#define LL 256
#define MM 256
#define NN 256

#define bx 16
#define by 8
#define bz 8

#define bx1 8

void check_error (const char* message) {
	cudaError_t error = cudaGetLastError ();
	if (error != cudaSuccess) {
		printf ("CUDA error : %s, %s\n", message, cudaGetErrorString (error));
		exit(-1);
	}
}

__global__ void fusion (double * __restrict__ d_ppgc, double * __restrict__ d_ppgk, double * __restrict__ d_wgtfac, double * __restrict__ d_ppuv, int L, int M, int N) {
	int tid = threadIdx.x + threadIdx.y * blockDim.x + threadIdx.z * blockDim.x * blockDim.y;
	int threadIdx_x, threadIdx_y, threadIdx_z;
	int blockDim_x, blockDim_y, blockDim_z;
	if(tid < 512){
		blockDim_x = 8;
		blockDim_y = 8;
		blockDim_z = 8;
		threadIdx_x = tid % blockDim_x;
		threadIdx_y = tid / blockDim_x % blockDim_y;
		threadIdx_z = tid / blockDim_x / blockDim_y % blockDim_z;
	}
	else{
		blockDim_x = 8;
		blockDim_y = 8;
		blockDim_z = 8;
		threadIdx_x = (tid - 512) % blockDim_x;
		threadIdx_y = (tid - 512) / blockDim_x % blockDim_y;
		threadIdx_z = (tid - 512) / blockDim_x / blockDim_y % blockDim_z;
	}
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*((int)blockDim_x);
	int i = i0 + (int)(threadIdx_x);
	int j0 = (int)(blockIdx.y)*((int)blockDim_y);
	int j = j0 + (int)(threadIdx_y);
	int k0 = (int)(blockIdx.z)*((int)blockDim_z);
	int k = k0 + (int)(threadIdx_z);

	double (*ppgc)[MM][NN] = (double (*)[MM][NN]) d_ppgc;
	double (*ppgk)[MM][NN] = (double (*)[MM][NN]) d_ppgk;
	double (*wgtfac)[MM][NN] = (double (*)[MM][NN]) d_wgtfac;
	double (*ppuv)[MM][NN] = (double (*)[MM][NN]) d_ppuv;

	//Array and variable declarations
	if(tid < 512){
		if (k >= max(1, k0) && k <= min(k0+blockDim.z-1, L-1) && j >= j0 && j <= min(j0+blockDim.y-1, M-1) && i >= i0 && i <= min(i0+blockDim.x-1, N-1)) {
			ppgk[k][j][i] = wgtfac[k][j][i] * ppuv[k][j][i] + (1.0 - wgtfac[k][j][i]) * ppuv[k-1][j][i];
		}
		asm("bar.sync 1, 512;");
	}
	else{
		if (k >= max(1, k0) && k <= min(k0+blockDim.z-2, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-1) && i >= i0 && i <= min(i0+blockDim.x-1, N-1)) {
			ppgc[k][j][i] = ppgk[k+1][j][i] - ppgk[k][j][i];
		}
	}
}


extern "C" void host_code (double *h_ppgc, double *h_ppgk, double *h_wgtfac, double *h_ppuv, int L, int M, int N) {
	cudaEvent_t start, stop; 
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	
	double *ppgc;
	cudaMalloc (&ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgc\n");
	cudaMemcpy (ppgc, h_ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppgk;
	cudaMalloc (&ppgk, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgk\n");
	cudaMemcpy (ppgk, h_ppgk, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *wgtfac;
	cudaMalloc (&wgtfac, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for wgtfac\n");
	cudaMemcpy (wgtfac, h_wgtfac, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppuv;
	cudaMalloc (&ppuv, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppuv\n");
	cudaMemcpy (ppuv, h_ppuv, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);

	dim3 blockconfig_1 (bx, by, bz); 
	dim3 gridconfig_1 (ceil (N, min(bx1, bx-bx1)), ceil (M, blockconfig_1.y), ceil (L, blockconfig_1.z));

	cudaEventRecord(start);
	fusion <<<gridconfig_1, blockconfig_1>>> (ppgc, ppgk, wgtfac, ppuv, L, M, N);;
	cudaEventRecord(stop);
	cudaMemcpy (h_ppgc, ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	cudaMemcpy (h_ppgk, ppgk, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);

	float time;
	cudaEventElapsedTime(&time, start, stop);
	printf("Kernel time %fs\n", time);
	printf("BlockDim1 (%d, %d, %d)\n", blockconfig_1.x, blockconfig_1.y, blockconfig_1.y);
	printf("GridDim (%d, %d, %d)\n", gridconfig_1.x, gridconfig_1.y, gridconfig_1.y);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
}