/**
*  File:    main.cpp
*  Author:  Hamza Hameed
*  Date:    September 1, 2015
*  Purpose: The main for our Pokemon game
*/
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Colosseum.h"
int main()
{
	std::string response;
	do
	{
		Pokemon pokemon1;
		Pokemon pokemon2;
		Colosseum colosseum;
		std::cout << "\nPlayer 1, build your Pokemon!\n";
		colosseum.userBuild(pokemon1);
		std::cout << "\nPlayer 2, build your Pokemon!\n";
		colosseum.userBuild(pokemon2);
		std::cout << "Choosing which player to go first...\n";
		std::cout << "\n";
		colosseum.play(pokemon1, pokemon2);
		std::cout << "Do you want to play again? (y/n)\n";
		std::cin >> response;
	}while(response=="y");
	return (0);
}
