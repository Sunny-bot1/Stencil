extern "C" void fusion (double *ppgu_in0, double *ppgu_in1, double *ppuv_in, double *ppgc_in, double *hhl_in, int N) {
	double (*ppgu0)[128][128] = (double (*)[128][128])ppgu_in0;
	double (*ppgu1)[128][128] = (double (*)[128][128])ppgu_in1;
	double (*ppuv)[128][128] = (double (*)[128][128])ppuv_in;
	double (*ppgc)[128][128] = (double (*)[128][128])ppgc_in;
	double (*hhl)[128][128] = (double (*)[128][128])hhl_in;

	int i,j, k;
	for (k = 0; k < N-1; k++) {
		for (j = 0; j < N-1; j++) {
			for (i = 0; i < N-1; i++) {
				ppgu0[k][j][i] = (ppuv[k][j][i+1] - ppuv[k][j][i]) +
                    (ppgc[k][j][i+1] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j][i+1] + hhl[k][j][i+1])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j][i+1] + hhl[k][j][i+1])); 
                ppgu1[k][j][i] = (ppuv[k][j+1][i] - ppuv[k][j][i]) +
                    (ppgc[k][j+1][i] + ppgc[k][j][i]) * 0.5 * ((hhl[k+1][j][i] + hhl[k][j][i]) - (hhl[k+1][j+1][i] + hhl[k][j+1][i])) / ((hhl[k+1][j][i] - hhl[k][j][i]) + (hhl[k+1][j+1][i] + hhl[k][j+1][i]));
            }
        }   
    } 
}