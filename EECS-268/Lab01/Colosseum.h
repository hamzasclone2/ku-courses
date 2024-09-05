/**
*  File:    Colosseum.h
*  Author:  Hamza Hameed
*  Date:    September 1, 2015
*  Purpose: Header file for Colosseum class. This class builds the Pokemon
*  and handles the attacks
*/
#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"
class Colosseum
{
	private:
	Dice d20;
	Dice d6;
	Dice d2;
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Colosseum instance
	*  @return Initialized Dice with 2, 6, or 20 sides
	*/
	Colosseum();
	/**
	*  @pre p is a valid Pokemon
	*  @post Creates and initializes a Colosseum instance
	*  @return Initialized Dice with 2, 6, or 20 sides
	*/
	void userBuild(Pokemon& p);
	/**
	*  @pre None
	*  @post Initializes pokemon based on user input
	*  @return none
	*/
	bool attack(const Pokemon& attacker, Pokemon& defender);
	/**
	*  @pre attacker and defender are valid pokemon
	*  @post attackerhas either attacked or missed based on dice roll
	*  @return truth if defender has fainted
	*/
	void play(Pokemon& p1, Pokemon& p2);
};
#endif
