#!/bin/bash

#20 40 40
#20 40 20
#20 40 10
#20 40 4
#20 40 1
#20 20 1
#20 10 1
#20 4 1
#20 2 1
N=6
UNROLL_K_LIST=(5 10 20 40 40 40 40)
UNROLL_J_LIST=(1  1  1  1  2  4  8 )

for ((i=0; i<N; i++))
do
    k="${UNROLL_K_LIST[$i]}"
    j="${UNROLL_J_LIST[$i]}"
    parameter1="fastwave.idsl"
    parameter2="--blockdim x=16,y=8,z=8"
    parameter3="--unroll k=${k},j=${j},i=1"
    parameter4="--ndim L=320,M=320,N=320"

    file="out.cu"
    #./stencilgen fastwave.idsl --blockdim x=16,y=8,z=8 --unroll k=1,j=1,i=1 --ndim L=320,M=320,N=320
    ./stencilgen $parameter1 $parameter2 $parameter3 $parameter4 >> genlog.txt
    
    original_code='fastwave <<<gridconfig_1, blockconfig_1>>> (ppgu, ppuv, ppgc, hhl, L, M, N);'

    replacement_code='cudaEvent_t start, stop; 
    cudaEventCreate(\&start);
    cudaEventCreate(\&stop);
    cudaEventRecord(start);
    fastwave <<<gridconfig_1, blockconfig_1>>> (ppgu, ppuv, ppgc, hhl, L, M, N);
    printf("%d,%d,%d,%d,", gridconfig_1.x, gridconfig_1.y, gridconfig_1.z, gridconfig_1.x*gridconfig_1.y*gridconfig_1.z);
    cudaEventRecord(stop);
    cudaMemcpy (h_ppgu, ppgu, sizeof(double )*(L - 0)*(M - 0)*(N - 0), cudaMemcpyDeviceToHost);
    float time;
    cudaEventElapsedTime(\&time, start, stop);
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    printf("%f\\n", time);'

    # 将代码段的内容进行转义，将换行符替换为换行符转义符（\n）
    escaped_original_code=$(echo "$original_code" | sed ':a;N;$!ba;s/\n/\\n/g')
    escaped_replacement_code=$(echo "$replacement_code" | sed ':a;N;$!ba;s/\n/\\n/g')

    # delete
    sed -i '/cudaMemcpyDeviceToHost/d' "$file"
    # replacement
    sed -i "s|$escaped_original_code|$escaped_replacement_code|g" "$file"

    make >> makelog.txt
    ./a.out >> grid_time.txt
done