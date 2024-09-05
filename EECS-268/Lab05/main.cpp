/*
@file: main.cpp
@author: Hamza Hameed
@date: October 19, 2015
@brief: contains goodbyeMessage() and main. Creates animals, allows users to
		decide how much milk or how many eggs are produced, then releases
		all animals from the pen
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "Stack.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"
#include "AnimalPen.h"

void goodbyeMessage(const FarmAnimal& animal){
	std::cout << "Upon release the " << animal.getName() << " said " <<
	animal.getSound() << ".\n";
}

int main(){
	std::string yORn="";//as long as user choose n or N, program runs
	int choice;//used to choose either cow, chicken, or cyberChicken
	double gallons;
	int eggs;
	int animalCounter=0;//runs for loop during release
	double totalGallons=0;
	int totalEggs=0;
	AnimalPen* animalPen=new AnimalPen();
	Cow* cow=new Cow();
	Chicken* chicken=new Chicken();
	CyberChicken* cyberChicken=new CyberChicken();
	do{
		std::cout << "\nSelect an animal to add to the pen:\n"
				  << "1. Cow (produces milk)\n"
				  << "2. Chicken (cannot lay eggs)\n"
				  << "3. Cyber Chicken (seems dangerous, but lays eggs)\n"
				  << "-------------------------------------------------\n"
				  << "Choice: ";
		std::cin >> choice;
		if(choice==1){
			animalCounter++;
			animalPen->addAnimal(cow);
			std::cout << "How many gallons of milk did this cow produce?: ";
			std::cin >> gallons;
			totalGallons+=gallons;
			cow->setMilkProduced(gallons);
			std::cout << "Done adding animals? (y/n): ";
			std::cin >> yORn;
		}
		else if(choice==2){
			animalCounter++;
			animalPen->addAnimal(chicken);
			std::cout << "Add an eggless chicken to the pen? I mean, ok I guess...\n"
			 		  		<< "Done adding animals? (y/n): ";
			std::cin >> yORn;
		}
		else if(choice==3){
			animalCounter++;
			animalPen->addAnimal(cyberChicken);
			std::cout << "How many eggs did this cyber chicken produce?: ";
			std::cin >> eggs;
			totalEggs+=eggs;
			cyberChicken->setCyberEggs(eggs);
			std::cout << "Done adding animals? (y/n): ";
			std::cin >> yORn;
		}
		else{
			std::cout << "\nWhat? That's not an option! Try again...\n";
			yORn="n";
		}
	}while(yORn=="n" || yORn=="N");
	std::cout << "\nReleasing all animals!\n"
			  		<< "----------------------\n";
	for(int i=0; i<animalCounter; i++){
		if(animalPen->peekAtNextAnimal()->getName()=="Cow"){
			std::cout << "This cow produced " << cow->getMilkProduced()
					  		<< " gallons of milk.\n";
		}
		else if(animalPen->peekAtNextAnimal()->getName()=="CyberChicken"){
			std::cout << "This Cyber Chicken laid " << cyberChicken->getCyberEggs()
					  		<< " eggs. Humanity is in trouble.\n";
		}
		else{//for chicken case
			std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?\n";
		}
		goodbyeMessage(*(animalPen->peekAtNextAnimal()));
		animalPen->releaseAnimal();
	}
	std::cout << "Your farm produced " << totalGallons << " gallons of milk and "
			  		<< totalEggs << " eggs.\n";
	delete animalPen;
	delete cow;
	delete chicken;
	delete cyberChicken;
  return(0);
}
