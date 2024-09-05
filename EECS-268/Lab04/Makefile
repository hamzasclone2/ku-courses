lab04: main.o PreconditionViolationException.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o PreconditionViolationException.o -o lab04

main.o: main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp Test.h PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c main.cpp

Test.o: Test.cpp Test.h Stack.h
	g++ -g -std=c++11 -Wall -c Test.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o lab04
	echo clean done
