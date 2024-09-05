/** 
*  File:    Pokemon.cpp
*  Author:  Hamza Hameed
*  Date:    September 1, 2015
*  Purpose: Implementation of Pokemon class
*/
#include "Pokemon.h"
Pokemon::Pokemon()
{
	m_hp=0;
	m_attackLevel=0;
	m_defenseLevel=0;
	m_name="";
}
void Pokemon::reduceHP(int amount)
{
	m_hp = m_hp - amount;
}
void Pokemon::setHP(int hp)
{
	m_hp=hp;
}
int Pokemon::getHP() const
{
	return(m_hp);
}
void Pokemon::setAttackLevel(int attackLevel)
{
	m_attackLevel=attackLevel;
}
int Pokemon::getAttackLevel() const
{
	return(m_attackLevel);
}
void Pokemon::setDefenseLevel(int defenseLevel)
{
	m_defenseLevel=defenseLevel;
}
int Pokemon::getDefenseLevel() const
{
	return(m_defenseLevel);
}
void Pokemon::setName(std::string name)
{
	m_name=name;
}
std::string Pokemon::getName() const
{
	return(m_name);
}