#include <stdio.h>
#include "cuda.h"
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))
#define ceil(a,b)   ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

#define LL 320
#define MM 320
#define NN 320

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

__global__ void fastwave1 (double * __restrict__ d_ppgu, double * __restrict__ d_ppuv, double * __restrict__ d_ppgc, double * __restrict__ d_hhl, int L, int M, int N) {
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*((int)blockDim.x);
	int i = i0 + (int)(threadIdx.x);
	int j0 = (int)(blockIdx.y)*((int)blockDim.y);
	int j = j0 + (int)(threadIdx.y);
	int k0 = (int)(blockIdx.z)*((int)blockDim.z);
	int k = k0 + (int)(threadIdx.z);

	double (*ppgu)[MM][NN] = (double (*)[MM][NN]) d_ppgu;
	double (*ppuv)[MM][NN] = (double (*)[MM][NN]) d_ppuv;
	double (*ppgc)[MM][NN] = (double (*)[MM][NN]) d_ppgc;
	double (*hhl)[MM][NN] = (double (*)[MM][NN]) d_hhl;

	//Array and variable declarations

	if (k >= k0 && k <= min(k0+blockDim.z-1, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-1) && i >= i0 && i <= min(i0+blockDim.x-1, N-2)) {
		ppgu[k][j][i] = (ppuv[k][j][i+1] - ppuv[k][j][i]) + (ppgc[k][j][i+1] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j][i+1] + hhl[k][j][i+1])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j][i+1] + hhl[k][j][i+1]));
	}
}

__global__ void fastwave2 (double * __restrict__ d_ppgu, double * __restrict__ d_ppuv, double * __restrict__ d_ppgc, double * __restrict__ d_hhl, int L, int M, int N) {
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*((int)blockDim.x);
	int i = i0 + (int)(threadIdx.x);
	int j0 = (int)(blockIdx.y)*((int)blockDim.y);
	int j = j0 + (int)(threadIdx.y);
	int k0 = (int)(blockIdx.z)*((int)blockDim.z);
	int k = k0 + (int)(threadIdx.z);

	double (*ppgu)[MM][NN] = (double (*)[MM][NN]) d_ppgu;
	double (*ppuv)[MM][NN] = (double (*)[MM][NN]) d_ppuv;
	double (*ppgc)[MM][NN] = (double (*)[MM][NN]) d_ppgc;
	double (*hhl)[MM][NN] = (double (*)[MM][NN]) d_hhl;

	//Array and variable declarations

	if (k >= k0 && k <= min(k0+blockDim.z-1, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-2) && i >= i0 && i <= min(i0+blockDim.x-1, N-1)) {
		ppgu[k][j][i] = (ppuv[k][j+1][i] - ppuv[k][j][i]) + (ppgc[k][j+1][i] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j+1][i] + hhl[k][j+1][i])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j+1][i] + hhl[k][j+1][i]));
	}
}


extern "C" void host_code (double *h_ppgu0, double *h_ppgu1,double *h_ppuv, double *h_ppgc, double *h_hhl, int L, int M, int N) {
	
	cudaEvent_t start, stop; 
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	
	cudaStream_t s1, s2;
	cudaStreamCreate(&s1);
	cudaStreamCreate(&s2);
	
	double *ppgu0;
	cudaMalloc (&ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgu0\n");
	//cudaMemcpy (ppgu0, h_ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppgu1;
	cudaMalloc (&ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgu1\n");
	//cudaMemcpy (ppgu1, h_ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *ppuv;
	cudaMalloc (&ppuv, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppuv\n");
	cudaMemcpyAsync (ppuv, h_ppuv, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice, s1);
	double *ppgc;
	cudaMalloc (&ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgc\n");
	cudaMemcpyAsync (ppgc, h_ppgc, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice, s1);
	double *hhl;
	cudaMalloc (&hhl, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for hhl\n");
	cudaMemcpyAsync (hhl, h_hhl, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice, s1);

	dim3 blockconfig_1 (bx, by, bz);
	dim3 gridconfig_1 (ceil (N - 1 - 0 + 1, blockconfig_1.x), ceil (M - 1 - 0 + 1, blockconfig_1.y), ceil (L - 1 - 0 + 1, blockconfig_1.z));
	cudaEventRecord(start);
	fastwave1 <<<gridconfig_1, blockconfig_1, 0, s1>>> (ppgu0, ppuv, ppgc, hhl, L, M, N);
	fastwave2 <<<gridconfig_1, blockconfig_1, 0, s2>>> (ppgu1, ppuv, ppgc, hhl, L, M, N);
	cudaEventRecord(stop);
	cudaMemcpyAsync (h_ppgu0, ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost, s1);
	cudaMemcpyAsync (h_ppgu1, ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost, s2);
	
	cudaStreamDestroy(s1);
	cudaStreamDestroy(s2);
	
	float time;
	cudaEventElapsedTime(&time, start, stop);
	printf("Kernel time %fs\n", time);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
}