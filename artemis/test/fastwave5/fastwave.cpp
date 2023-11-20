#include "common/common.hpp"
#include "fastwave.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 320; 

	double (*ppgc)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppgk)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	
    double (*ppgc_gold)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
    memcpy(ppgc, ppgc_gold, sizeof(double)*N*N*N);
	fastwave ((double*)ppgc_gold, (double*)ppgk, N);
	host_code ((double*)ppgc, (double*)ppgk, N, N, N);

	double error_0 = checkError3D<double> (N, N, (double*)ppgc, (double*)ppgc_gold, 0, N-1, 0, N-1, 0, N-1);
	printf("[Test] RMS Error : %e\n",error_0);
	if (error_0 > TOLERANCE)
	 	return -1;

	delete[] ppgk;
    delete[] ppgc_gold;
	delete[] ppgc;
    return 0;
}
