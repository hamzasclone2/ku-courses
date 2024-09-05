/**
*  File:    Colosseum.cpp
*  Author:  Hamza Hameed
*  Date:    September 1, 2015
*  Purpose: Implementation of Colosseum class
*/
#include "Colosseum.h"
Colosseum::Colosseum()
{
	d20=Dice(20);
	d2=Dice(2);
	d6=Dice();
}
void Colosseum::userBuild(Pokemon& p)
{
	std::string name;
	int hp;
	int attackLevel;
	int defenseLevel;
	int defenseLevelLimit;
	std::cout << "=============================\n";
	std::cout << "Please name your pokemon:\n";
	std::cin >> name;
	do
	{
	std::cout << "How many hit points will it have? (1-50):\n";
	std::cin >> hp;
	if(hp<1 || hp>50)
	{
		std::cout << "Sorry, the hp must be between 1 and 50\n";
	}
	}while(hp<1 || hp>50);
	std::cout << "Split fifty points between attack level and defense level\n";
	do
	{
	std::cout << "Enter your attack level (1-49):\n";
	std::cin >> attackLevel;
	if(attackLevel<1 || attackLevel>49)
	{
		std::cout << "Sorry, the attack level must be between 1 and 50\n";
	}
	}while(attackLevel<1 || attackLevel>49);
	defenseLevelLimit=50-attackLevel;
	do
	{
	std::cout << "Enter your defense level (1-" << defenseLevelLimit << "):\n";
	std::cin >> defenseLevel;
	if(defenseLevel<1 || defenseLevel>defenseLevelLimit)
	{
		std::cout << "Sorry, the defense level must be between 1 and "
		<< defenseLevelLimit << std::endl;
	}
	}while(defenseLevel<1 || defenseLevel>defenseLevelLimit);
	std::cout << "\n";
	p.setName(name);
  p.setHP(hp);
  p.setAttackLevel(attackLevel);
	p.setDefenseLevel(defenseLevel);
}
bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{
	int attackBonus;
	int defenseBonus;
	int totalAttack;
	int totalDefense;
	int attack1;
	int attack2;
	int attack3;
	int totalDamage;
	std::cout << attacker.getName() << " is attacking " << defender.getName()
	<< "!\n";
	attackBonus=d20.roll();
	std::cout << attacker.getName() << " rolls an attack bonus of " <<
	attackBonus << "!\n";
	defenseBonus=d20.roll();
	std::cout << defender.getName() << " rolls a defense bonus of " <<
	defenseBonus << "!\n";
	totalAttack=attackBonus+attacker.getAttackLevel();
	totalDefense=defenseBonus+defender.getDefenseLevel();
	if(totalAttack>totalDefense)
	{
		std::cout << "The attack hits dealing 3-D6 damage!\n";
		attack1=d6.roll();
		attack2=d6.roll();
		attack3=d6.roll();
		totalDamage=attack1+attack2+attack3;
		std::cout << "The attack did " << attack1 << ", " << attack2
		<< ", and " << attack3 << " damage! Totaling " << totalDamage
		<< " damage!\n";
		defender.reduceHP(totalDamage);
		if(defender.getHP()<1)
		{
				std::cout << defender.getName() << " fainted!\n";
				std::cout << "\n";
				return(true);
		}
		std::cout << defender.getName() << " has " << defender.getHP()
		<< " hitpoints left.\n";
		std::cout << "\n";
		return(false);
	}
	else
	{
		std::cout << "The attack missed!\n";
		std::cout << defender.getName() << " has " << defender.getHP()
		<< " hitpoints left.\n";
		std::cout << "\n";
		return(false);
	}
}
void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	int roll;
	roll=d2.roll();
	if(roll==1)
	{
		std::cout << p1.getName() << " will go first!\n";
	}
	else
	{
		std::cout << p2.getName() << " will go first!\n";
	}
	if(p1.getHP()>0 && p2.getHP()>0)
	{
		for (int i=1; i<12; i++)
		{
			if(i==11)
			{
				std::cout << "It's a draw!\n";
				i++;
			}
			else
			{
				std::cout << "Round " << i << "!\n";
				std::cout << "\n";
				if(roll==1)
				{
					attack(p1, p2);
					if(p2.getHP()>0)
					{
					attack(p2, p1);
					}
				}
				else
				{
					attack(p2, p1);
					if(p2.getHP()>0)
					{
					attack(p1, p2);
					}
				}
				if(p1.getHP()<0 || p2.getHP()<0)
				{
					i=i+10;
				}
 			}
		}
	}
}
