#include <stdio.h>
#include "cuda.h"
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))
#define ceil(a,b)   ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

#define LL 128
#define MM 128
#define NN 128

#define bx 16
#define by 8
#define bz 8

void check_error (const char* message) {
	cudaError_t error = cudaGetLastError ();
	if (error != cudaSuccess) {
		printf ("CUDA error : %s, %s\n", message, cudaGetErrorString (error));
		exit(-1);
	}
}

__global__ void fusion (double * __restrict__ d_ppgu0, double * __restrict__ d_ppgu1, double * __restrict__ d_ppuv, double * __restrict__ d_ppgc, double * __restrict__ d_hhl, int L, int M, int N) {
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*((int)blockDim.x);
	int i = i0 + (int)(threadIdx.x);
	int j0 = (int)(blockIdx.y)*((int)blockDim.y);
	int j = j0 + (int)(threadIdx.y);
	int k0 = (int)(blockIdx.z)*((int)blockDim.z);
	int k = k0 + (int)(threadIdx.z);

	double (*ppgu0)[MM][NN] = (double (*)[MM][NN]) d_ppgu0;
	double (*ppgu1)[MM][NN] = (double (*)[MM][NN]) d_ppgu1;
	double (*ppuv)[MM][NN] = (double (*)[MM][NN]) d_ppuv;
	double (*ppgc)[MM][NN] = (double (*)[MM][NN]) d_ppgc;
	double (*hhl)[MM][NN] = (double (*)[MM][NN]) d_hhl;

	//Array and variable declarations

	if (k >= k0 && k <= min(k0+blockDim.z-1, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-1) && i >= i0 && i <= min(i0+blockDim.x-1, N-2)) {
		ppgu0[k][j][i] = (ppuv[k][j][i+1] - ppuv[k][j][i]) + (ppgc[k][j][i+1] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j][i+1] + hhl[k][j][i+1])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j][i+1] + hhl[k][j][i+1]));
	}
	if (k >= k0 && k <= min(k0+blockDim.z-1, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-2) && i >= i0 && i <= min(i0+blockDim.x-1, N-1)) {
		ppgu1[k][j][i] = (ppuv[k][j][i+1] - ppuv[k][j][i]) + (ppgc[k][j][i+1] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j][i+1] + hhl[k][j][i+1])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j][i+1] + hhl[k][j][i+1]));
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
	dim3 gridconfig_1 (ceil (N - 1 - 0 + 1, blockconfig_1.x), ceil (M - 1 - 0 + 1, blockconfig_1.y), ceil (L - 1 - 0 + 1, blockconfig_1.z));
	cudaEventRecord(start);
	fusion <<<gridconfig_1, blockconfig_1>>> (ppgu0, ppgu1, ppuv, ppgc, hhl, L, M, N);
	cudaEventRecord(stop);
	cudaMemcpy (h_ppgu0, ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	cudaMemcpy (h_ppgu1, ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);

	float time;
	cudaEventElapsedTime(&time, start, stop);
	printf("Kernel time %fs\n", time);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
}