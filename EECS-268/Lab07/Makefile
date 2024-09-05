lab07: main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o Test.o
	g++ -g -std=c++11 -Wall main.o SortDriver.o NumberFileGenerator.o NumberFileDriver.o Test.o -o lab07

main.o: main.cpp Sorts.h Sorts.hpp SortDriver.h NumberFileGenerator.h NumberFileDriver.h Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

SortDriver.o: SortDriver.h SortDriver.cpp
	g++ -g -std=c++11 -Wall -c SortDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -Wall -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp NumberFileGenerator.h
	g++ -g -std=c++11 -Wall -c NumberFileDriver.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp

clean:
	rm *.o lab06
	echo clean done
