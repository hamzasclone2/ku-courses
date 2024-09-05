PokemonGame: main.o Dice.o Colosseum.o Pokemon.o
	g++ -std=c++11 -g -Wall main.o Dice.o Colosseum.o Pokemon.o -o PokemonGame

main.o: main.cpp Dice.h Pokemon.h
	g++ -std=c++11 -g -Wall -c main.cpp

Dice.o: Dice.h Dice.cpp
	g++ -std=c++11 -g -Wall -c Dice.cpp
	
Colosseum.o: Colosseum.h Colosseum.cpp Pokemon.h Dice.h
	g++ -std=c++11 -g -Wall -c Colosseum.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

clean: 
	rm *.o PokemonGame
	echo clean done