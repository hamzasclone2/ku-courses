Lab06: main.o List.o Hash.o closedHash.o Node.o timerClass.o
	g++ -std=c++11 -o Lab06 main.o List.o Hash.o closedHash.o Node.o timerClass.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
List.o: List.cpp List.h
	g++ -std=c++11 -c List.cpp
Hash.o: Hash.cpp Hash.h
    g++ -std=c++11 -c Hash.cpp
closedHash.o: closedHash.cpp Hash.h
    g++ -std=c++11 -c closedHash.cpp
timerClass.o: timerClass.cpp
	g++ -std=c++11 -c timerClass.cpp
clean:
	rm -f *.o *~ Lab06
