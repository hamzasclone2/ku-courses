Lab05: main.o twoThreeTree.o
	g++ -std=c++11 -o Lab05 main.o twoThreeTree.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
twoThreeTree.o: twoThreeTree.cpp twoThreeTree.h
	g++ -std=c++11 -c twoThreeTree.cpp
clean:
	rm -f *.o *~ Lab05
