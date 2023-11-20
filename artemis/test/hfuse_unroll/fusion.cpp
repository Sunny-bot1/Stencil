#include "common/common.hpp"
#include "fusion.gold.h"
#include <cassert>
#include <cstdio>

extern "C" void host_code (double*, double*, double*, double*, double*, int, int, int);

int main(int argc, char** argv) {
	int N = 128; 

	double (*ppgu0)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*ppgu1)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*ppuv)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*ppgc)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*hhl)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	
    double (*ppgu_gold0)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
	double (*ppgu_gold1)[128][128] = (double (*)[128][128]) getRandom3DArray<double>(128, 128, 128);
    memcpy(ppgu0, ppgu_gold0, sizeof(double)*N*N*N);
	memcpy(ppgu1, ppgu_gold1, sizeof(double)*N*N*N);
	fusion ((double*)ppgu_gold0, (double*)ppgu_gold1, (double*)ppuv, (double*)ppgc, (double*)hhl, N);
	host_code ((double*)ppgu0, (double*)ppgu1, (double*)ppuv, (double*)ppgc, (double*)hhl, N, N, N);


	double error_0 = checkError3D<double> (N, N, (double*)ppgu0, (double*)ppgu_gold0, 0, N-1, 0, N-1, 0, N-1);
	printf("[Test] RMS Error : %e\n",error_0);
	double error_1 = checkError3D<double> (N, N, (double*)ppgu1, (double*)ppgu_gold1, 0, N-1, 0, N-1, 0, N-1);
	printf("[Test] RMS Error : %e\n",error_1);
	// if (error_0 > TOLERANCE)
	//  	return -1;

	// FILE *file;
	// if((file=fopen("hf.txt", "w+")) == NULL){
	// 	printf("can not open file\n");
	// 	return -1;
	// }
	// for(int i = 0; i < 128; i++){
	// 	for(int j = 0; j < 128; j++){
	// 		for(int k = 0; k < 128; k++){
	// 			fprintf(file, "%d %d %d : %lf %lf vs %lf %lf\n", i, j, k, ppgu0[i][j][k], ppgu1[i][j][k], ppgu_gold0[i][j][k], ppgu_gold1[i][j][k]);
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
