CXX = /usr/bin/g++
AR = ar -rcs

INCLUDE=-I$(PREFIX)/include \
		-I$(PREFIX)/include/opencv \
		-I$(PREFIX)/include/opencv2

OPENCV_LIBS = -lopencv_highgui -lopencv_imgcodecs -llibjasper -llibjpeg -llibtiff -llibpng -llibwebp -lopencv_imgproc -lopencv_core  -lpthread -lstdc++ -fopenmp -ldl -lz

LIBS = -L$(PREFIX)/lib \
        -lIPCReading-S-r0.0.1 -lDNN -lopenblas\
		$(OPENCV_LIBS) 

DEFINE =-O3 -fPIC -msse2 -msse3 -msse4 -mfpmath=sse -ffast-math -funroll-loops -std=c++11

.PHONY: all clean

EXE=./run_multi_threads
PREFIX=./test

run: 
	cd main && go run main.go cfunc.go	

clean:
	@rm -f $(EXE)

golang: 
	$(CXX) -c -o $(PREFIX)/test.o $(PREFIX)/test.cpp $(DEFINE) $(INCLUDE) $(LIBS) && ar -rs $(PREFIX)/lib/libtest.a $(PREFIX)/test.o
