/*
*	@file : main.cpp
*	@author :  Hamza Hameed
*	@date : September 29, 2015
*	@brief: The input and output of the whole program
*/

#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "Test.h"
#include <stdexcept>

void printMenu()
{
    std::cout << 	"\n\nMake choice\n"
              <<	"1) Push value onto front\n"
              <<	"2) Push value onto back\n"
              <<	"3) Insert behind a value\n"
              <<	"4) Insert ahead of a value\n"
              <<	"5) Remove front value\n"
              <<	"6) Remove back value\n"
              <<	"7) Remove specific value\n"
              <<	"8) Print list\n"
              <<	"9) Quit\n"
              << 	"10) Run Tests\n"
              << 	"Your choice: ";
}

int main()
{
	DoubleLinkedList<int>* list = new DoubleLinkedList<int>;
	bool isRunning = true;
	int input;
	int input2;
	while(isRunning){
		printMenu();
		std::cin >> input;
		if(input == 1){
			std::cout << "You chose: " << input << "\n";
			std::cout << "Give a value.\n";
			std::cin >> input;
			list->pushFront(input);
			std::cout << "\n" << input << " added to front of list.\n";
		}
		if(input == 2){
			std::cout << "You chose: " << input << "\n";
			std::cout << "Give a value.\n";
			std::cin >> input;
			list->pushBack(input);
			std::cout << "\n" << input << " added to back of list.\n";
		}
		if(input == 3){
			std::cout << "You chose: " << input << "\n";
			std::cout << "Give a value to insert.\n";
			std::cin >> input;
			std::cout << "Pick a value to insert behind.\n";
			std::cin >> input2;
			std::cout << "\nAttempting to insert " << input << " behind " << input2 << "\n";
			try {
				list->insertBehind(input2, input);
				std::cout << "\n" << input << " inserted behind " << input2 << "\n";
			}
			catch (std::runtime_error& e) {
				std::cout << e.what();
			}
		}
		if(input == 4){
			std::cout << "You chose: " << input << "\n";
			std::cout << "Give a value to insert.\n";
			std::cin >> input;
			std::cout << "Pick a value to insert ahead of.\n";
			std::cin >> input2;
			std::cout << "\nAttempting to insert " << input << " ahead of " << input2 << "\n\n";
			try {
				list->insertAhead(input2, input);
				std::cout << "\n" << input << " inserted ahead " << input2 << "\n";
			}
			catch (std::runtime_error& e) {
				std::cout << e.what();
			}
		}
        if (input == 5){
            std::cout << "You chose: " << input << "\n";
            bool success = list->removeFront();
            if(success)
                std::cout << "\nFront of list removed.\n";
            else
                std::cout << "\nList empty\n";
        }
        if (input == 6){
            std::cout << "You chose : " << input << "\n";
            bool success = list->removeBack();
            if(success)
                std::cout << "\nBack of list removed.\n";
            else
                std::cout << "\nList empty\n";
        }
		if(input == 7){
			std::cout << "You chose : " << input << "\n";
			std::cout << "Give a value to remove. ";
			std::cin >> input;
			std::cout << "You gave " << input;
			bool success = list->remove(input);
			if(success)
				std::cout << "\n" << input << " removed from list.\n";
			else
				std::cout << "\n" << input << " could not be removed from list.\n";
		}
		if(input == 8){
			std::cout << "You chose : " << input << "\n";
			list->printList();
		}
		if(input == 9) {
            std::cout << "You chose : " << input << "\n";
			isRunning = false;
			std::cout << "Program ending…\n";
		}
        if (input == 10){
            Test myTester(std::cout);
            myTester.runTests();
        }
	}
	delete list;
	return(0);
}
