extern "C" void fastwave (double *ppgc_in, double *ppgk_in, int N) {
	double (*ppgc)[320][320] = (double (*)[320][320])ppgc_in;
	double (*ppgk)[320][320] = (double (*)[320][320])ppgk_in;

	int i,j, k;
	for (k = 0; k < N; k++) {
		for (j = 0; j < N; j++) {
			for (i = 0; i < N; i++) {
				ppgc[k][j][i] = ppgk[k+1][j][i] - ppgk[k][j][i];
            }
        }   
    } 
}