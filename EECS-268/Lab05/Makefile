lab05: main.o PreconditionViolationException.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o AnimalPen.o -o lab05

main.o: main.cpp Node.h Node.hpp StackInterface.h Stack.h Stack.hpp PreconditionViolationException.h FarmAnimal.h Cow.h Chicken.h CyberChicken.h AnimalPen.h
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -Wall -c FarmAnimal.cpp

Cow.o: Cow.h Cow.cpp FarmAnimal.h
	g++ -g -std=c++11 -Wall -c Cow.cpp

Chicken.o: Chicken.h Chicken.cpp FarmAnimal.h
	g++ -g -std=c++11 -Wall -c Chicken.cpp

CyberChicken.o: CyberChicken.h CyberChicken.cpp Chicken.h
	g++ -g -std=c++11 -Wall -c CyberChicken.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp Stack.h FarmAnimal.h
	g++ -g -std=c++11 -Wall -c AnimalPen.cpp

clean:
	rm *.o lab05
	echo clean done
