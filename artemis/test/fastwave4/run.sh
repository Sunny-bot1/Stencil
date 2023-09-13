#!/bin/bash
echo $@
./stencilgen $@ > /dev/null 2>&1
if [ $? -ne 0 ];
then
    echo "Generation Error!"
    exit 0
fi
file="out.cu"
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

make > /dev/null 2>&1
if [ $? -ne 0 ];
then
    echo "Compilation Error!"
    exit 0
fi

./a.out >> grid_time.txt

# nvprof --csv --profile-api-trace none -u ms ./a.out 2>&1 \
#     | grep -v "\[CUDA memcpy " | grep -P "([[:digit:].]+,){6}" \
#     | cut -d, -f 6 | python ~/python/calc.py;
# if [ ${PIPESTATUS[0]} -ne 0 ];
# then
#     echo "Run Error!"
#     exit 0
# fi
