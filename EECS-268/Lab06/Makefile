lab06: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o lab06

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp

clean:
		rm *.o lab06
		echo clean done
