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

__global__ void fusion (double * __restrict__ d_ppgu0, double * __restrict__ d_ppgu1, double * __restrict__ d_ppuv, double * __restrict__ d_ppgc, double * __restrict__ d_hhl, int L, int M, int N) {
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

	// double (*ppgu0)[MM][NN] = (double (*)[MM][NN]) d_ppgu0;
	// double (*ppgu1)[MM][NN] = (double (*)[MM][NN]) d_ppgu1;
	double (*ppuv)[MM][NN] = (double (*)[MM][NN]) d_ppuv;
	double (*ppgc)[MM][NN] = (double (*)[MM][NN]) d_ppgc;
	double (*hhl)[MM][NN] = (double (*)[MM][NN]) d_hhl;

	//Array and variable declarations
	if(tid < 512){
		double (*ppgu0)[MM][NN] = (double (*)[MM][NN]) d_ppgu0;
		if (k >= k0 && k <= min(k0+blockDim_z-1, L-2) && j >= j0 && j <= min(j0+blockDim_y-1, M-1) && i >= i0 && i <= min(i0+blockDim_x-1, N-2)) {
			ppgu0[k][j][i] = (ppuv[k][j][i+1] - ppuv[k][j][i]) + (ppgc[k][j][i+1] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j][i+1] + hhl[k][j][i+1])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j][i+1] + hhl[k][j][i+1]));
		}
	}
	else{
		double (*ppgu1)[MM][NN] = (double (*)[MM][NN]) d_ppgu1;
		if (k >= k0 && k <= min(k0+blockDim_z-1, L-2) && j >= j0 && j <= min(j0+blockDim_y-1, M-2) && i >= i0 && i <= min(i0+blockDim_x-1, N-1)) {
			ppgu1[k][j][i] = (ppuv[k][j+1][i] - ppuv[k][j][i]) + (ppgc[k][j+1][i] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j+1][i] + hhl[k][j+1][i])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j+1][i] + hhl[k][j+1][i]));
		}
	}
}


extern "C" void host_code (double *h_ppgu0, double *h_ppgu1, double *h_ppuv, double *h_ppgc, double *h_hhl, int L, int M, int N) {
	cudaEvent_t start, stop; 
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	
	double *ppgu0;
	cudaMalloc (&ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgu0\n");
	cudaMemcpy (ppgu0, h_ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppgu1;
	cudaMalloc (&ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgu1\n");
	cudaMemcpy (ppgu1, h_ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppuv;
	cudaMalloc (&ppuv, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppuv\n");
	cudaMemcpy (ppuv, h_ppuv, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppgc;
	cudaMalloc (&ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgc\n");
	cudaMemcpy (ppgc, h_ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *hhl;
	cudaMalloc (&hhl, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for hhl\n");
	cudaMemcpy (hhl, h_hhl, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);

	dim3 blockconfig_1 (bx, by, bz); 
	dim3 gridconfig_1 (ceil (N, min(bx1, bx-bx1)), ceil (M, blockconfig_1.y), ceil (L, blockconfig_1.z));

	cudaEventRecord(start);
	fusion <<<gridconfig_1, blockconfig_1>>> (ppgu0, ppgu1, ppuv, ppgc, hhl, L, M, N);
	cudaEventRecord(stop);
	cudaMemcpy (h_ppgu0, ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	cudaMemcpy (h_ppgu1, ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);

	float time;
	cudaEventElapsedTime(&time, start, stop);
	printf("Kernel time %fs\n", time);
	printf("BlockDim1 (%d, %d, %d)\n", blockconfig_1.x, blockconfig_1.y, blockconfig_1.y);
	printf("GridDim (%d, %d, %d)\n", gridconfig_1.x, gridconfig_1.y, gridconfig_1.y);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
}