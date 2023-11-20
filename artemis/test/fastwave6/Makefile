ARCH=sm_60
MAXREGCOUNT=128
ifdef DEBUG
OPTFLAGS=-O0 -g -maxrregcount=$(MAXREGCOUNT) -ccbin=g++ -std=c++11 -Xcompiler "-fPIC -g -O0 -fno-strict-aliasing" --use_fast_math -Xptxas "-dlcm=ca"
else
OPTFLAGS=-maxrregcount=$(MAXREGCOUNT) -ccbin=g++ -std=c++11 -Xcompiler "-fPIC -fopenmp -fno-strict-aliasing" --use_fast_math -Xptxas "-dlcm=ca"
endif
.DEFAULT_GOAL := fastwave
gold:
	nvcc fastwave.cpp out.cu -arch=$(ARCH) $(OPTFLAGS)
	./a.out
clean:
	rm test.txt gold.txt
fastwave:
	nvcc fastwave.cpp out.cu -arch=$(ARCH) $(OPTFLAGS)
