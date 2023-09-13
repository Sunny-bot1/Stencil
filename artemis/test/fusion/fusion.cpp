#include "common/common.hpp"
#include "fusion.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 128; 

	double (*ppgu0)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppgu1)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppuv)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppgc)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*hhl)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	
    double (*ppgu_gold0)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppgu_gold1)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
    //memcpy(ppgu, ppgu_gold, sizeof(double)*N*N*N);
	fusion ((double*)ppgu_gold0, (double*)ppgu_gold1, (double*)ppuv, (double*)ppgc, (double*)hhl, N);
	host_code ((double*)ppgu0, (double*)ppgu1, (double*)ppuv, (double*)ppgc, (double*)hhl, N, N, N);


	// double error_0 = checkError3D<double> (N, N, (double*)ppgu0, (double*)ppgu_gold0, 0, N-1, 0, N-1, 0, N-1);
	// printf("[Test] RMS Error : %e\n",error_0);
	// if (error_0 > TOLERANCE)
	//  	return -1;

	delete[] ppgu0;
	delete[] ppgu1;
    delete[] ppgu_gold0;
	delete[] ppgu_gold1;
	delete[] ppuv;
	delete[] ppgc;
	delete[] hhl;
    return 0;
}
