extern "C" void fastwave (double *ppgu_in, double *ppuv_in, double *ppgc_in, double *hhl_in, int N) {
	double (*ppgu)[320][320] = (double (*)[320][320])ppgu_in;
	double (*ppuv)[320][320] = (double (*)[320][320])ppuv_in;
	double (*ppgc)[320][320] = (double (*)[320][320])ppgc_in;
	double (*hhl)[320][320] = (double (*)[320][320])hhl_in;

	int i,j, k;
	for (k = 0; k < N-1; k++) {
		for (j = 0; j < N-1; j++) {
			for (i = 0; i < N-1; i++) {
                ppgu[k][j][i] = (ppuv[k][j][i+1] - ppuv[k][j][i]) +
                    (ppgc[k][j][i+1] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j][i+1] + hhl[k][j][i+1])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j][i+1] + hhl[k][j][i+1])); 
            }
        }   
    } 
}