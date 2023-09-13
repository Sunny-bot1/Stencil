#include <stdio.h>
#include "cuda.h"
#define max(x,y)    ((x) > (y) ? (x) : (y))
#define min(x,y)    ((x) < (y) ? (x) : (y))
#define ceil(a,b)   ((a) % (b) == 0 ? (a) / (b) : ((a) / (b)) + 1)

#define LL 320
#define MM 320
#define NN 320

#define bx 16
#define by 32
#define bz 8

void check_error (const char* message) {
	cudaError_t error = cudaGetLastError ();
	if (error != cudaSuccess) {
		printf ("CUDA error : %s, %s\n", message, cudaGetErrorString (error));
		exit(-1);
	}
}

__global__ void addsg (double * __restrict__ d_up_0, double * __restrict__ d_up_1, double * __restrict__ d_up_2, double * __restrict__ d_u_0, double * __restrict__ d_u_1, double * __restrict__ d_u_2, double * __restrict__ d_um_0, double * __restrict__ d_um_1, double * __restrict__ d_um_2, double * __restrict__ d_rho, double * __restrict__ strx, double * __restrict__ stry, double * __restrict__ strz, double * __restrict__ dcx, double * __restrict__ dcy, double * __restrict__ dcz, double * __restrict__ cox, double * __restrict__ coy, double * __restrict__ coz, int L, int M, int N) {
	//Determining the block's indices
	int i0 = (int)(blockIdx.x)*((int)blockDim.x);
	int i = i0 + (int)(threadIdx.x);
	int j0 = (int)(blockIdx.y)*((int)blockDim.y);
	int j = j0 + (int)(threadIdx.y);

	double (*up_0)[MM][NN] = (double (*)[MM][NN]) d_up_0;
	double (*up_1)[MM][NN] = (double (*)[MM][NN]) d_up_1;
	double (*up_2)[MM][NN] = (double (*)[MM][NN]) d_up_2;
	double (*u_0)[MM][NN] = (double (*)[MM][NN]) d_u_0;
	double (*u_1)[MM][NN] = (double (*)[MM][NN]) d_u_1;
	double (*u_2)[MM][NN] = (double (*)[MM][NN]) d_u_2;
	double (*um_0)[MM][NN] = (double (*)[MM][NN]) d_um_0;
	double (*um_1)[MM][NN] = (double (*)[MM][NN]) d_um_1;
	double (*um_2)[MM][NN] = (double (*)[MM][NN]) d_um_2;
	double (*rho)[MM][NN] = (double (*)[MM][NN]) d_rho;

	//Array and variable declarations
	double birho;
	double beta = 0.625;

	#pragma unroll 4
	for (int k=2; k<=L-3; k++) {
		if (j >= max(2, j0) && j <= min(j0+blockDim.y-1, M-3) && i >= max(2, i0) && i <= min(i0+blockDim.x-1, N-3)) {
			birho = beta / rho[k][j][i];
			up_0[max (0, k)][j][i] -= birho * (strx[i] * coy[j] * coz[k] * (rho[k][j][i+1] * dcx[i+1] * (u_0[k][j][i+2] - 2 * u_0[k][j][i+1] + u_0[k][j][i]) - 2 * rho[k][j][i] * dcx[i] * (u_0[k][j][i+1] - 2 * u_0[k][j][i] + u_0[k][j][i-1]) + rho[k][j][i-1] * dcx[i-1] * (u_0[k][j][i] - 2 * u_0[k][j][i-1] + u_0[k][j][i-2]) - rho[k][j][i+1] * dcx[i+1] * (um_0[k][j][i+2] - 2 * um_0[k][j][i+1] + um_0[k][j][i]) + 2 * rho[k][j][i] * dcx[i] * (um_0[k][j][i+1] - 2 * um_0[k][j][i] + um_0[k][j][i-1]) - rho[k][j][i-1] * dcx[i-1] * (um_0[k][j][i] - 2 * um_0[k][j][i-1] + um_0[k][j][i-2])) + stry[j] * cox[i] * coz[k] * (rho[k][j+1][i] * dcy[j+1] * (u_0[k][j+2][i] - 2 * u_0[k][j+1][i] + u_0[k][j][i]) - 2 * rho[k][j][i] * dcy[j] * (u_0[k][j+1][i] - 2 * u_0[k][j][i] + u_0[k][j-1][i]) + rho[k][j-1][i] * dcy[j-1] * (u_0[k][j][i] - 2 * u_0[k][j-1][i] + u_0[k][j-2][i]) - rho[k][j+1][i] * dcy[j+1] * (um_0[k][j+2][i] - 2 * um_0[k][j+1][i] + um_0[k][j][i]) + 2 * rho[k][j][i] * dcy[j] * (um_0[k][j+1][i] - 2 * um_0[k][j][i] + um_0[k][j-1][i]) - rho[k][j-1][i] * dcy[j-1] * (um_0[k][j][i] - 2 * um_0[k][j-1][i] + um_0[k][j-2][i])) + strz[k] * cox[i] * coy[j] * (rho[k+1][j][i] * dcz[k+1] * (u_0[k+2][j][i] - 2 * u_0[k+1][j][i] + u_0[k][j][i]) - 2 * rho[k][j][i] * dcz[k] * (u_0[k+1][j][i] - 2 * u_0[k][j][i] + u_0[k-1][j][i]) + rho[k-1][j][i] * dcz[k-1] * (u_0[k][j][i] - 2 * u_0[k-1][j][i] + u_0[k-2][j][i]) - rho[k+1][j][i] * dcz[k+1] * (um_0[k+2][j][i] - 2 * um_0[k+1][j][i] + um_0[k][j][i]) + 2 * rho[k][j][i] * dcz[k] * (um_0[k+1][j][i] - 2 * um_0[k][j][i] + um_0[k-1][j][i]) - rho[k-1][j][i] * dcz[k-1] * (um_0[k][j][i] - 2 * um_0[k-1][j][i] + um_0[k-2][j][i])));
			up_1[max (0, k)][j][i] -= birho * (strx[i] * coy[j] * coz[k] * (rho[k][j][i+1] * dcx[i+1] * (u_1[k][j][i+2] - 2 * u_1[k][j][i+1] + u_1[k][j][i]) - 2 * rho[k][j][i] * dcx[i] * (u_1[k][j][i+1] - 2 * u_1[k][j][i] + u_1[k][j][i-1]) + rho[k][j][i-1] * dcx[i-1] * (u_1[k][j][i] - 2 * u_1[k][j][i-1] + u_1[k][j][i-2]) - rho[k][j][i+1] * dcx[i+1] * (um_1[k][j][i+2] - 2 * um_1[k][j][i+1] + um_1[k][j][i]) + 2 * rho[k][j][i] * dcx[i] * (um_1[k][j][i+1] - 2 * um_1[k][j][i] + um_1[k][j][i-1]) - rho[k][j][i-1] * dcx[i-1] * (um_1[k][j][i] - 2 * um_1[k][j][i-1] + um_1[k][j][i-2])) + stry[j] * cox[i] * coz[k] * (rho[k][j+1][i] * dcy[j+1] * (u_1[k][j+2][i] - 2 * u_1[k][j+1][i] + u_1[k][j][i]) - 2 * rho[k][j][i] * dcy[j] * (u_1[k][j+1][i] - 2 * u_1[k][j][i] + u_1[k][j-1][i]) + rho[k][j-1][i] * dcy[j-1] * (u_1[k][j][i] - 2 * u_1[k][j-1][i] + u_1[k][j-2][i]) - rho[k][j+1][i] * dcy[j+1] * (um_1[k][j+2][i] - 2 * um_1[k][j+1][i] + um_1[k][j][i]) + 2 * rho[k][j][i] * dcy[j] * (um_1[k][j+1][i] - 2 * um_1[k][j][i] + um_1[k][j-1][i]) - rho[k][j-1][i] * dcy[j-1] * (um_1[k][j][i] - 2 * um_1[k][j-1][i] + um_1[k][j-2][i])) + strz[k] * cox[i] * coy[j] * (rho[k+1][j][i] * dcz[k+1] * (u_1[k+2][j][i] - 2 * u_1[k+1][j][i] + u_1[k][j][i]) - 2 * rho[k][j][i] * dcz[k] * (u_1[k+1][j][i] - 2 * u_1[k][j][i] + u_1[k-1][j][i]) + rho[k-1][j][i] * dcz[k-1] * (u_1[k][j][i] - 2 * u_1[k-1][j][i] + u_1[k-2][j][i]) - rho[k+1][j][i] * dcz[k+1] * (um_1[k+2][j][i] - 2 * um_1[k+1][j][i] + um_1[k][j][i]) + 2 * rho[k][j][i] * dcz[k] * (um_1[k+1][j][i] - 2 * um_1[k][j][i] + um_1[k-1][j][i]) - rho[k-1][j][i] * dcz[k-1] * (um_1[k][j][i] - 2 * um_1[k-1][j][i] + um_1[k-2][j][i])));
			up_2[max (0, k)][j][i] -= birho * (strx[i] * coy[j] * coz[k] * (rho[k][j][i+1] * dcx[i+1] * (u_2[k][j][i+2] - 2 * u_2[k][j][i+1] + u_2[k][j][i]) - 2 * rho[k][j][i] * dcx[i] * (u_2[k][j][i+1] - 2 * u_2[k][j][i] + u_2[k][j][i-1]) + rho[k][j][i-1] * dcx[i-1] * (u_2[k][j][i] - 2 * u_2[k][j][i-1] + u_2[k][j][i-2]) - rho[k][j][i+1] * dcx[i+1] * (um_2[k][j][i+2] - 2 * um_2[k][j][i+1] + um_2[k][j][i]) + 2 * rho[k][j][i] * dcx[i] * (um_2[k][j][i+1] - 2 * um_2[k][j][i] + um_2[k][j][i-1]) - rho[k][j][i-1] * dcx[i-1] * (um_2[k][j][i] - 2 * um_2[k][j][i-1] + um_2[k][j][i-2])) + stry[j] * cox[i] * coz[k] * (rho[k][j+1][i] * dcy[j+1] * (u_2[k][j+2][i] - 2 * u_2[k][j+1][i] + u_2[k][j][i]) - 2 * rho[k][j][i] * dcy[j] * (u_2[k][j+1][i] - 2 * u_2[k][j][i] + u_2[k][j-1][i]) + rho[k][j-1][i] * dcy[j-1] * (u_2[k][j][i] - 2 * u_2[k][j-1][i] + u_2[k][j-2][i]) - rho[k][j+1][i] * dcy[j+1] * (um_2[k][j+2][i] - 2 * um_2[k][j+1][i] + um_2[k][j][i]) + 2 * rho[k][j][i] * dcy[j] * (um_2[k][j+1][i] - 2 * um_2[k][j][i] + um_2[k][j-1][i]) - rho[k][j-1][i] * dcy[j-1] * (um_2[k][j][i] - 2 * um_2[k][j-1][i] + um_2[k][j-2][i])) + strz[k] * cox[i] * coy[j] * (rho[k+1][j][i] * dcz[k+1] * (u_2[k+2][j][i] - 2 * u_2[k+1][j][i] + u_2[k][j][i]) - 2 * rho[k][j][i] * dcz[k] * (u_2[k+1][j][i] - 2 * u_2[k][j][i] + u_2[k-1][j][i]) + rho[k-1][j][i] * dcz[k-1] * (u_2[k][j][i] - 2 * u_2[k-1][j][i] + u_2[k-2][j][i]) - rho[k+1][j][i] * dcz[k+1] * (um_2[k+2][j][i] - 2 * um_2[k+1][j][i] + um_2[k][j][i]) + 2 * rho[k][j][i] * dcz[k] * (um_2[k+1][j][i] - 2 * um_2[k][j][i] + um_2[k-1][j][i]) - rho[k-1][j][i] * dcz[k-1] * (um_2[k][j][i] - 2 * um_2[k-1][j][i] + um_2[k-2][j][i])));
		}
	}
}


extern "C" void host_code (double *h_up_0, double *h_up_1, double *h_up_2, double *h_u_0, double *h_u_1, double *h_u_2, double *h_um_0, double *h_um_1, double *h_um_2, double *h_rho, double *h_strx, double *h_stry, double *h_strz, double *h_dcx, double *h_dcy, double *h_dcz, double *h_cox, double *h_coy, double *h_coz, int L, int M, int N) {
	double *up_0;
	cudaMalloc (&up_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for up_0\n");
	cudaMemcpy (up_0, h_up_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *up_1;
	cudaMalloc (&up_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for up_1\n");
	cudaMemcpy (up_1, h_up_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *up_2;
	cudaMalloc (&up_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for up_2\n");
	cudaMemcpy (up_2, h_up_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *u_0;
	cudaMalloc (&u_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for u_0\n");
	cudaMemcpy (u_0, h_u_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *u_1;
	cudaMalloc (&u_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for u_1\n");
	cudaMemcpy (u_1, h_u_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *u_2;
	cudaMalloc (&u_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for u_2\n");
	cudaMemcpy (u_2, h_u_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *um_0;
	cudaMalloc (&um_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for um_0\n");
	cudaMemcpy (um_0, h_um_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *um_1;
	cudaMalloc (&um_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for um_1\n");
	cudaMemcpy (um_1, h_um_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *um_2;
	cudaMalloc (&um_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for um_2\n");
	cudaMemcpy (um_2, h_um_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *rho;
	cudaMalloc (&rho, sizeof(double )*(L - 0)*(M - 0)*(N - 0));
	check_error ("Failed to allocate device memory for rho\n");
	cudaMemcpy (rho, h_rho, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyHostToDevice);
	double *strx;
	cudaMalloc (&strx, sizeof(double )*(N - 0));
	check_error ("Failed to allocate device memory for strx\n");
	cudaMemcpy (strx, h_strx, sizeof(double )*(N - 0), cudaMemcpyHostToDevice);
	double *stry;
	cudaMalloc (&stry, sizeof(double )*(M - 0));
	check_error ("Failed to allocate device memory for stry\n");
	cudaMemcpy (stry, h_stry, sizeof(double )*(M - 0), cudaMemcpyHostToDevice);
	double *strz;
	cudaMalloc (&strz, sizeof(double )*(L - 0));
	check_error ("Failed to allocate device memory for strz\n");
	cudaMemcpy (strz, h_strz, sizeof(double )*(L - 0), cudaMemcpyHostToDevice);
	double *dcx;
	cudaMalloc (&dcx, sizeof(double )*(N - 0));
	check_error ("Failed to allocate device memory for dcx\n");
	cudaMemcpy (dcx, h_dcx, sizeof(double )*(N - 0), cudaMemcpyHostToDevice);
	double *dcy;
	cudaMalloc (&dcy, sizeof(double )*(M - 0));
	check_error ("Failed to allocate device memory for dcy\n");
	cudaMemcpy (dcy, h_dcy, sizeof(double )*(M - 0), cudaMemcpyHostToDevice);
	double *dcz;
	cudaMalloc (&dcz, sizeof(double )*(L - 0));
	check_error ("Failed to allocate device memory for dcz\n");
	cudaMemcpy (dcz, h_dcz, sizeof(double )*(L - 0), cudaMemcpyHostToDevice);
	double *cox;
	cudaMalloc (&cox, sizeof(double )*(N - 0));
	check_error ("Failed to allocate device memory for cox\n");
	cudaMemcpy (cox, h_cox, sizeof(double )*(N - 0), cudaMemcpyHostToDevice);
	double *coy;
	cudaMalloc (&coy, sizeof(double )*(M - 0));
	check_error ("Failed to allocate device memory for coy\n");
	cudaMemcpy (coy, h_coy, sizeof(double )*(M - 0), cudaMemcpyHostToDevice);
	double *coz;
	cudaMalloc (&coz, sizeof(double )*(L - 0));
	check_error ("Failed to allocate device memory for coz\n");
	cudaMemcpy (coz, h_coz, sizeof(double )*(L - 0), cudaMemcpyHostToDevice);

	dim3 blockconfig_1 (bx, by, 1);
	dim3 gridconfig_1 (ceil (N - 1 - 0 + 1, blockconfig_1.x), ceil (M - 1 - 0 + 1, blockconfig_1.y), 1);

	addsg <<<gridconfig_1, blockconfig_1>>> (up_0, up_1, up_2, u_0, u_1, u_2, um_0, um_1, um_2, rho, strx, stry, strz, dcx, dcy, dcz, cox, coy, coz, L, M, N);

	cudaMemcpy (h_up_0, up_0, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	cudaMemcpy (h_up_1, up_1, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
	cudaMemcpy (h_up_2, up_2, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
}