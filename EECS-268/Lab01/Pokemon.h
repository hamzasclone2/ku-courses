/**
*  File:    Pokemon.h
*  Author:  Hamza Hameed
*  Date:    September 1, 2015
*  Purpose: Header file for Pokemon class. Used to construct Pokemon and reduce hp
*/
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
class Pokemon
{
	private:
	int m_hp;
	int m_attackLevel;
	int m_defenseLevel;
	std::string m_name;
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a Pokemon instance
	*  @return Initialized Pokemon with empty values
	*/
	Pokemon();
	/**
	*  @pre amount is >= 1
	*  @post reduces hp of pokemon
	*  @return none
	*/
	void reduceHP(int amount);
	/**
	*  @pre hp is >= 1
	*  @post sets m_hp to hp
	*  @return none
	*/
	void setHP(int hp);
	/**
	*  @pre none
	*  @post none
	*  @return returns value of m_hp
	*/
	int getHP() const;
	/**
	*  @pre attackLevel is >= 1
	*  @post sets m_attackLevel to attackLevel
	*  @return none
	*/
	void setAttackLevel(int attackLevel);
	/**
	*  @pre none
	*  @post none
	*  @return returns value of m_attackLevel
	*/
	int getAttackLevel() const;
	/**
	*  @pre defenseLevel is >= 1
	*  @post sets value of m_defenseLevel to defenseLevel
	*  @return none
	*/
	void setDefenseLevel(int defenseLevel);
	/**
	*  @pre none
	*  @post none
	*  @return returns value of m_defenseLevel
	*/
	int getDefenseLevel() const;
	/**
	*  @pre name is a valid string
	*  @post sets value of m_name to name
	*  @return none
	*/
	void setName(std::string name);
	/**
	*  @pre none
	*  @post none
	*  @return returns value of m_name
	*/
	std::string getName() const;
};
#endif
