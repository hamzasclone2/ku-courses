project2: project2.o ../lib/libCOGLImageReader.so
	mpic++ -o project2 project2.o ../lib/libCOGLImageReader.so
project2.o: project2.c++
	mpic++ -c -std=c++11 -I../Packed3DArray -I../ImageReader project2.c++
../lib/libCOGLImageReader.so: ../ImageReader/ImageReader.h ../ImageReader/ImageReader.c++ ../Packed3DArray/Packed3DArray.h
	(cd ../ImageReader; make)
