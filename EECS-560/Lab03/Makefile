Lab03: main.o Hash.o
	g++ -std=c++11 -o Lab03 main.o Hash.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Hash.o: Hash.cpp Hash.h
	g++ -std=c++11 -c Hash.cpp
clean:
	rm -f *.o *~ Lab03
