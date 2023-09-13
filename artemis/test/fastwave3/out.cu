#include <stdio.h>
#include "cuda.h"
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))
#define ceil(a,b)   ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

#define LL 320
#define MM 320
#define NN 320

#define bx 32
#define by 4
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
	int i0 = (int)(blockIdx.x)*((int)blockDim.x);
	int i = i0 + (int)(threadIdx.x);
	int j0 = (int)(blockIdx.y)*(16*(int)blockDim.y);
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
		#pragma unroll 16
		for (int r0_j16 = 0, j16 = j; r0_j16 < 16; r0_j16++, j16+=blockDim.y) {
			if (k2 >= k0 && k2 <= min(k0+2*blockDim.z-1, L-2) && j16 >= j0 && j16 <= min(j0+16*blockDim.y-1, M-2) && i >= i0 && i <= min(i0+blockDim.x-1, N-1)) {
				ppgu[k2][j16][i] = (ppuv[k2][j16+1][i] - ppuv[k2][j16][i]) + (ppgc[k2][j16+1][i] + ppgc[k2][j16][i]) * 0.5 * ((hhl[k2+1][j16][i] + hhl[k2][j16][i]) - (hhl[k2+1][j16+1][i] + hhl[k2][j16+1][i])) / ((hhl[k2+1][j16][i] - hhl[k2][j16][i]) + (hhl[k2+1][j16+1][i] + hhl[k2][j16+1][i]));
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
	dim3 gridconfig_1 (ceil (N - 1 - 0 + 1, blockconfig_1.x), ceil (M - 1 - 0 + 1, 16*blockconfig_1.y), ceil (L - 1 - 0 + 1, 2*blockconfig_1.z));

	fastwave <<<gridconfig_1, blockconfig_1>>> (ppgu, ppuv, ppgc, hhl, L, M, N);

	cudaMemcpy (h_ppgu, ppgu, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
}