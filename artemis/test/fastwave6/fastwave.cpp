#include "common/common.hpp"
#include "fastwave.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 320; 

	double (*ppgk)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*wgtfac)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	double (*ppuv)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
	
    double (*ppgk_gold)[320][320] = (double (*)[320][320]) getRandom3DArray<double>(320, 320, 320);
    memcpy(ppgk, ppgk_gold, sizeof(double)*N*N*N);
	fastwave ((double*)ppgk_gold, (double*)wgtfac, (double*)ppuv, N);
	host_code ((double*)ppgk, (double*)wgtfac, (double*)ppuv, N, N, N);

	double error_0 = checkError3D<double> (N, N, (double*)ppgk, (double*)ppgk_gold, 0, N-1, 0, N-1, 0, N-1);
	printf("[Test] RMS Error : %e\n",error_0);
	if (error_0 > TOLERANCE)
	 	return -1;

	delete[] ppgk;
    delete[] ppgk_gold;
	delete[] wgtfac;
	delete[] ppuv;
    return 0;
}
