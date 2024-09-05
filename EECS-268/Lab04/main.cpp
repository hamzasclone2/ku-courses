/*
@file: main.cpp
@author: Hamza Hameed
@date: October 5, 2015
@brief: contains printMenu and the main where user
		chooses what to do with stack
*/
#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "Test.h"
#include "Stack.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"
void printMenu(){
	std::cout 	<< "\n\nSelect an action:\n"
			    << "1) Add to stack 1\n"
			    << "2) See what is at the top of stack\n"
			    << "3) Print all stack\n"
			    << "4) Pop stack\n"
			    << "5) Quit\n"
 			    << "6) Run Tests\n"
			    << "Enter choice: ";
}
int main(){
	int choice;
	int input;
	bool isRunning=true;
	StackInterface<int>* stack=new Stack<int>();
	while(isRunning){
		printMenu();
		std::cin >> choice;
		if(choice==1){ //adds value to top of stack
			std::cout << "You chose: 1\n"
					  << "What is going in stack 1?: ";
			std::cin >> input;
			stack->push(input);
			std::cout << stack->peek() << " successfully added to stack 1";
		}
		else if(choice==2){ //checks to see what is at top
			std::cout << "You chose: 2\n";
			try{
				std::cout << stack -> peek() << " is at the top of stack 1";
			}
			catch(std::exception e){
				std::cout << e.what();
			}
		}
		else if(choice==3){ //prints out list of stack
			std::cout << "You chose: 3\n";
			stack->print();
		}
		else if(choice==4){ //pops top of list
			std::cout << "You chose: 4\n";
			try{
				std::cout << stack -> peek() << " removed from stack 1";
				stack ->pop();
			}
			catch(std::exception& e){
				std::cout << e.what();
			}
		}
		else if(choice==5){ //quits out of program
			std::cout << "You chose: 5\n"
					  << "Program Ending\n";
			isRunning=false;
		}
		else if(choice==6){ //runs test for program
			std::cout << "You chose: 6\n";
			Test myTester(std::cout);
            myTester.runTests();
		}
	}
	delete stack;
    return(0);
}
