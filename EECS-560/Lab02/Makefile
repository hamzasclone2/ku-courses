Lab02: main.o List.o Node.o Hash.o
	g++ -std=c++11 -o Lab02 main.o List.o Node.o Hash.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
List.o: List.cpp List.h
	g++ -std=c++11 -c List.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
Hash.o: Hash.cpp Hash.h
	g++ -std=c++11 -c Hash.cpp
clean:
	rm -f *.o *~ Lab02
