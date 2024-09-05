Lab01: main.o List.o Node.o
	g++ -std=c++11 -o Lab01 main.o List.o Node.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
List.o: List.cpp List.h
	g++ -std=c++11 -c List.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm -f *.o *~ Lab01
