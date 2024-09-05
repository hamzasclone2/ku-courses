Lab07: main.o min5heap.o max5heap.o
	g++ -std=c++11 -o Lab07 main.o min5heap.o max5heap.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
min5heap.o: min5heap.cpp min5heap.h
	g++ -std=c++11 -c min5heap.cpp
max5heap.o: max5heap.cpp max5heap.h
	g++ -std=c++11 -c max5heap.cpp
clean:
	rm -f *.o *~ Lab07
