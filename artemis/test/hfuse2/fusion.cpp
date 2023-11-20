#include "common/common.hpp"
#include "fusion.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 256; 

	double (*ppgc)[256][256] = (double (*)[256][256]) getRandom3DArray<double>(256, 256, 256);
	double (*ppgk)[256][256] = (double (*)[256][256]) getRandom3DArray<double>(256, 256, 256);
	double (*wgtfac)[256][256] = (double (*)[256][256]) getRandom3DArray<double>(256, 256, 256);
	double (*ppuv)[256][256] = (double (*)[256][256]) getRandom3DArray<double>(256, 256, 256);
	
    //double (*ppgu_gold0)[256][256] = (double (*)[256][256]) getRandom3DArray<double>(256, 256, 256);
	//double (*ppgu_gold1)[256][256] = (double (*)[256][256]) getRandom3DArray<double>(256, 256, 256);
    //memcpy(ppgu0, ppgu_gold0, sizeof(double)*N*N*N);
	//memcpy(ppgu1, ppgu_gold1, sizeof(double)*N*N*N);
	//fusion ((double*)ppgu_gold0, (double*)ppgu_gold1, (double*)ppuv, (double*)ppgc, (double*)hhl, N);
	host_code ((double*)ppgc, (double*)ppgk, (double*)wgtfac, (double*)ppuv, N, N, N);


	// double error_0 = checkError3D<double> (N, N, (double*)ppgu0, (double*)ppgu_gold0, 0, N-1, 0, N-1, 0, N-1);
	// printf("[Test] RMS Error : %e\n",error_0);
	// double error_1 = checkError3D<double> (N, N, (double*)ppgu1, (double*)ppgu_gold1, 0, N-1, 0, N-1, 0, N-1);
	// printf("[Test] RMS Error : %e\n",error_1);
	// if (error_0 > TOLERANCE)
	//  	return -1;

	// FILE *file;
	// if((file=fopen("hf.txt", "w+")) == NULL){
	// 	printf("can not open file\n");
	// 	return -1;
	// }
	// for(int i = 0; i < 256; i++){
	// 	for(int j = 0; j < 256; j++){
	// 		for(int k = 0; k < 256; k++){
	// 			fprintf(file, "%d %d %d : %lf %lf vs %lf %lf\n", i, j, k, ppgu0[i][j][k], ppgu1[i][j][k], ppgu_gold0[i][j][k], ppgu_gold1[i][j][k]);
	// 		}
	// 	}
	// }
	// fclose(file);

	delete[] ppuv;
	delete[] ppgc;
	delete[] ppgk;
	delete[] wgtfac;
    return 0;
}
