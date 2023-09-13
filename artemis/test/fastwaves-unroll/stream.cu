#include <stdio.h>
#include "cuda.h"
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))
#define ceil(a,b)   ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

#define LL 320
#define MM 320
#define NN 320

#define bx 8
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
	int i0 = (int)(blockIdx.x)*(2*(int)blockDim.x);
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
	#pragma unroll 2
	for (int r0_i2 = 0, i2 = i; r0_i2 < 2; r0_i2++, i2+=blockDim.x) {
		if (k >= k0 && k <= min(k0+blockDim.z-1, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-1) && i2 >= i0 && i2 <= min(i0+2*blockDim.x-1, N-2)) {
			ppgu[k][j][i2] = (ppuv[k][j][i2+1] - ppuv[k][j][i2]) + (ppgc[k][j][i2+1] + ppgc[k][j][i2]) * 0.5 * ((hhl[k+1][j][i2] + hhl[k][j][i]) - (hhl[k+1][j][i2+1] + hhl[k][j][i2+1])) / ((hhl[k+1][j][i2] - hhl[k][j][i2]) + (hhl[k+1][j][i2+1] + hhl[k][j][i2+1]));
		}
	}
}

__global__ void fastwave2 (double * __restrict__ d_ppgu, double * __restrict__ d_ppuv, double * __restrict__ d_ppgc, double * __restrict__ d_hhl, int L, int M, int N) {
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*(2*(int)blockDim.x);
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
	#pragma unroll 2
	for (int r0_i2 = 0, i2 = i; r0_i2 < 2; r0_i2++, i2+=blockDim.x) {
		if (k >= k0 && k <= min(k0+blockDim.z-1, L-2) && j >= j0 && j <= min(j0+blockDim.y-1, M-2) && i2 >= i0 && i2 <= min(i0+2*blockDim.x-1, N-2)) {
			ppgu[k][j][i2] = (ppuv[k][j+1][i2] - ppuv[k][j][i2]) + (ppgc[k][j+1][i2] + ppgc[k][j][i2]) * 0.5 * ((hhl[k+1][j][i2] + hhl[k][j][i2]) - (hhl[k+1][j+1][i2] + hhl[k][j+1][i2])) / ((hhl[k+1][j][i2] - hhl[k][j][i2]) + (hhl[k+1][j+1][i2] + hhl[k][j+1][i2]));
		}
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
	dim3 gridconfig_1 (ceil (N - 1 - 0 + 1, 2*blockconfig_1.x), ceil (M - 1 - 0 + 1, blockconfig_1.y), ceil (L - 1 - 0 + 1, blockconfig_1.z));
	cudaEventRecord(start);
	fastwave1 <<<gridconfig_1, blockconfig_1>>> (ppgu0, ppuv, ppgc, hhl, L, M, N);
	cudaError_t err0 = cudaGetLastError();
	if (err0 != cudaSuccess) {
		printf("CUDA Error: %s\n", cudaGetErrorString(err0));
		// Possibly: exit(-1) if program cannot continue....
	} 
	fastwave2 <<<gridconfig_1, blockconfig_1>>> (ppgu1, ppuv, ppgc, hhl, L, M, N);
	cudaError_t err1 = cudaGetLastError();
	if (err1 != cudaSuccess) {
		printf("CUDA Error: %s\n", cudaGetErrorString(err1));
		// Possibly: exit(-1) if program cannot continue....
	} 
	cudaEventRecord(stop);
	cudaMemcpyAsync (h_ppgu0, ppgu0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	cudaMemcpyAsync (h_ppgu1, ppgu1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	
	float time;
	cudaEventElapsedTime(&time, start, stop);
	printf("Kernel time %fs\n", time);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);
}