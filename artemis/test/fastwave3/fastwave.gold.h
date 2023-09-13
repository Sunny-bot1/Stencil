extern "C" void fastwave (double *ppgu_in, double *ppuv_in, double *ppgc_in, double *hhl_in, int N) {
	double (*ppgu)[128][128] = (double (*)[128][128])ppgu_in;
	double (*ppuv)[128][128] = (double (*)[128][128])ppuv_in;
	double (*ppgc)[128][128] = (double (*)[128][128])ppgc_in;
	double (*hhl)[128][128] = (double (*)[128][128])hhl_in;

	int i,j, k;
	for (k = 0; k < N-1; k++) {
		for (j = 0; j < N-1; j++) {
			for (i = 0; i < N-1; i++) {
                ppgu[k][j][i] = (ppuv[k][j+1][i] - ppuv[k][j][i]) +
                    (ppgc[k][j+1][i] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j+1][i] + hhl[k][j+1][i])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j+1][i] + hhl[k][j+1][i]));
            }
        }   
    } 
}