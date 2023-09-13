#include "common/common.hpp"
#include "fastwave.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 320; 

	double (*ppgu)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppuv)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppgc)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*hhl)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	
    double (*ppgu_gold)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
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
