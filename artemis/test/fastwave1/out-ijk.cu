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

__global__ void fastwave (double * __restrict__ d_ppgu, double * __restrict__ d_ppuv, double * __restrict__ d_ppgc, double * __restrict__ d_hhl, int L, int M, int N) {
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*(2*(int)blockDim.x);
	int i = i0 + (int)(threadIdx.x);
	int j0 = (int)(blockIdx.y)*(2*(int)blockDim.y);
	int j = j0 + (int)(threadIdx.y);
	int k0 = (int)(blockIdx.z)*(2*(int)blockDim.z);
	int k = k0 + (int)(threadIdx.z);

	double (*ppgu)[MM][NN] = (double (*)[MM][NN]) d_ppgu;
	double (*ppuv)[MM][NN] = (double (*)[MM][NN]) d_ppuv;
	double (*ppgc)[MM][NN] = (double (*)[MM][NN]) d_ppgc;
	double (*hhl)[MM][NN] = (double (*)[MM][NN]) d_hhl;

	//Array and variable declarations

	#pragma unroll 2
	for (int r0_k2 = 0, k2 = k; r0_k2 < 2; r0_k2++, k2+=blockDim.z) {
		#pragma unroll 2
		for (int r0_j2 = 0, j2 = j; r0_j2 < 2; r0_j2++, j2+=blockDim.y) {
			#pragma unroll 2
			for (int r0_i2 = 0, i2 = i; r0_i2 < 2; r0_i2++, i2+=blockDim.x) {
				if (k2 >= k0 && k2 <= min(k0+2*blockDim.z-1, L-2) && j2 >= j0 && j2 <= min(j0+2*blockDim.y-1, M-1) && i2 >= i0 && i2 <= min(i0+2*blockDim.x-1, N-2)) {
					ppgu[k2][j2][i2] = (ppuv[k2][j2][i2+1] - ppuv[k2][j2][i2]) + (ppgc[k2][j2][i2+1] + ppgc[k2][j2][i2]) * 0.5 * ((hhl[k2+1][j2][i2] + hhl[k2][j2][i2]) - (hhl[k2+1][j2][i2+1] + hhl[k2][j2][i2+1])) / ((hhl[k2+1][j2][i2] - hhl[k2][j2][i2]) + (hhl[k2+1][j2][i2+1] + hhl[k2][j2][i2+1]));
				}
			}
		}
	}
}


extern "C" void host_code (double *h_ppgu, double *h_ppuv, double *h_ppgc, double *h_hhl, int L, int M, int N) {
	double *ppgu;
	cudaMalloc (&ppgu, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for ppgu\n");
	cudaMemcpy (ppgu, h_ppgu, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
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
	dim3 gridconfig_1 (ceil (N - 1 - 0 + 1, 2*blockconfig_1.x), ceil (M - 1 - 0 + 1, 2*blockconfig_1.y), ceil (L - 1 - 0 + 1, 2*blockconfig_1.z));

	fastwave <<<gridconfig_1, blockconfig_1>>> (ppgu, ppuv, ppgc, hhl, L, M, N);

	cudaMemcpy (h_ppgu, ppgu, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
}