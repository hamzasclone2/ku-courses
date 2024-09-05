lab09: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o
	g++ -g -std=c++11 -Wall main.o  MazeReader.o MazeCreationException.o MazeWalker.o Position.o Test.o -o lab09

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -Wall -c MazeReader.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -Wall -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -Wall -c MazeWalker.cpp

Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -Wall -c Position.cpp

Test.o: Test.h Test.cpp ArrayHelper.h ArrayHelper.hpp
	g++ -g -std=c++11 -Wall -c Test.cpp

clean:
	rm *.o lab09
	echo clean done
