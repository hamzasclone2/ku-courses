Lab10: main.o leftistHeap.o skewHeap.o
	g++ -std=c++11 -o Lab10 main.o leftistHeap.o skewHeap.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
leftistHeap.o: leftistHeap.cpp leftistHeap.h
	g++ -std=c++11 -c leftistHeap.cpp
skewHeap.o: skewHeap.cpp skewHeap.h
	g++ -std=c++11 -c skewHeap.cpp
clean:
	rm -f *.o *~ Lab10
