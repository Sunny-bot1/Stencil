extern "C" void fusion (double *ppgc_in, double *ppgu_in1, double *ppuv_in, double *ppgc_in, double *hhl_in, int N) {
	double (*ppgc)[256][256] = (double (*)[256][256])ppgc_in;
	double (*ppgk)[256][256] = (double (*)[256][256])ppgk_in;
	double (*wgtfac)[256][256] = (double (*)[256][256])wgtfac_in;
	double (*ppuv)[256][256] = (double (*)[256][256])ppuv_in;

	int i,j, k;
	for (k = 0; k < N; k++) {
		for (j = 0; j < N; j++) {
			for (i = 0; i < N; i++) {
					ppgk[k][j][i] = wgtfac[k][j][i] * ppuv[k][j][i] +
                        (1.0 - wgtfac[k][j][i]) * ppuv[k - 1][j][i];
					ppgc[k][j][i] = ppgk[k+1][j][i] - ppgk[k][j][i];
            }
        }   
    } 
}