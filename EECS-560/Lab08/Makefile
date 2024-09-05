lab08: main.o minMax.o maxMin.o
	g++ -std=c++11 -o lab08 main.o minMax.o maxMin.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
minMax.o: minMax.cpp minMax.h
	g++ -std=c++11 -c minMax.cpp
maxMin.o: maxMin.cpp maxMin.h
	g++ -std=c++11 -c maxMin.cpp
clean:
	rm -f *.o *~ lab08
