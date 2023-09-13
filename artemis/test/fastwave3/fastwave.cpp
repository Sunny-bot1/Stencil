#include "common/common.hpp"
#include "fastwave.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 128; 

	double (*ppgu)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*ppuv)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*ppgc)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*hhl)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	
    double (*ppgu_gold)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
    memcpy(ppgu, ppgu_gold, sizeof(double)*N*N*N);
	fastwave ((double*)ppgu_gold, (double*)ppuv, (double*)ppgc, (double*)hhl, N);
	host_code ((double*)ppgu, (double*)ppuv, (double*)ppgc, (double*)hhl, N, N, N);


	// double error_0 = checkError3D<double> (N, N, (double*)ppgu, (double*)ppgu_gold, 0, N-1, 0, N-1, 0, N-1);
	// printf("[Test] RMS Error : %e\n",error_0);
	// if (error_0 > TOLERANCE)
	//  	return -1;

	delete[] ppgu;
    delete[] ppgu_gold;
	delete[] ppuv;
	delete[] ppgc;
	delete[] hhl;
    return 0;
}
