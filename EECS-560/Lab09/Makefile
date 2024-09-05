Lab09: main.o Node.o BST.o max5heap.o min5heap.o timerClass.o
	g++ -std=c++11 -o Lab09 main.o Node.o BST.o max5heap.o min5heap.o timerClass.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
BST.o: BST.cpp BST.h
	g++ -std=c++11 -c BST.cpp
max5heap.o: max5heap.cpp max5heap.h
	g++ -std=c++11 -c max5heap.cpp
min5heap.o: min5heap.cpp min5heap.h
	g++ -std=c++11 -c min5heap.cpp
timerClass.o: timerClass.cpp
	g++ -std=c++11 -c timerClass.cpp
clean:
	rm -f *.o *~ Lab09
