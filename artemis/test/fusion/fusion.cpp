#include "common/common.hpp"
#include "fusion.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 64; 

	double (*ppgu0)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
	double (*ppgu1)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
	double (*ppuv)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
	double (*ppgc)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
	double (*hhl)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
	
    double (*ppgu_gold0)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
	double (*ppgu_gold1)[64][64] = (double (*)[64][64]) getRandom3DArray<double>(64, 64, 64);
    memcpy(ppgu0, ppgu_gold0, sizeof(double)*N*N*N);
	memcpy(ppgu1, ppgu_gold1, sizeof(double)*N*N*N);
	fusion ((double*)ppgu_gold0, (double*)ppgu_gold1, (double*)ppuv, (double*)ppgc, (double*)hhl, N);
	host_code ((double*)ppgu0, (double*)ppgu1, (double*)ppuv, (double*)ppgc, (double*)hhl, N, N, N);


	double error_0 = checkError3D<double> (N, N, (double*)ppgu0, (double*)ppgu_gold0, 0, N-1, 0, N-1, 0, N-1);
	printf("[Test] RMS Error : %e\n",error_0);
	// if (error_0 > TOLERANCE)
	//  	return -1;
	// FILE *file;
	// if((file=fopen("vf.txt", "w+")) == NULL){
	// 	printf("can not open file\n");
	// 	return -1;
	// }
	// for(int i = 0; i < 64; i++){
	// 	for(int j = 0; j < 64; j++){
	// 		for(int k = 0; k < 64; k++){
	// 			fprintf(file, "%lf %lf vs %lf %lf\n", ppgu0[i][j][k], ppgu1[i][j][k], ppgu_gold0[i][j][k], ppgu_gold1[i][j][k]);
	// 		}
	// 	}
	// }
	// fclose(file);

	delete[] ppgu0;
	delete[] ppgu1;
    delete[] ppgu_gold0;
	delete[] ppgu_gold1;
	delete[] ppuv;
	delete[] ppgc;
	delete[] hhl;
    return 0;
}
