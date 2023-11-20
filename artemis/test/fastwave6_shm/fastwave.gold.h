extern "C" void fastwave (double *ppgk_in, double *wgtfac_in, double *ppuv_in, int N) {
	double (*ppgk)[320][320] = (double (*)[320][320])ppgk_in;
	double (*wgtfac)[320][320] = (double (*)[320][320])wgtfac_in;
	double (*ppuv)[320][320] = (double (*)[320][320])ppuv_in;

	int i,j, k;
	for (k = 1; k < N; k++) {
		for (j = 0; j < N; j++) {
			for (i = 0; i < N; i++) {
                ppgk[k][j][i] = wgtfac[k][j][i] * ppuv[k][j][i] + (1.0 - wgtfac[k][j][i]) * ppuv[k-1][j][i];
            }
        }   
    } 
}