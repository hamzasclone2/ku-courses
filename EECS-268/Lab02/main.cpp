/*
@author: Hamza Hameed
@file: main.cpp
@date: September 21, 2015
@brief: The main contains the printMenu function and uses LinkedLists functions
		to carry out what the user wants.
*/
#include <iostream>
#include "Test.h"
#include "LinkedList.h"
#include "Node.h"
void printMenu()
{
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "8) Run tests\n"
			<< "Enter your choice: ";
}
int main(){
    LinkedList*  linkedList=new LinkedList();
    bool isRunning=true;
    int choice;
    int value=0;
    while(isRunning){
        printMenu();
        std::cin >> choice;
        std::cout << "You chose: " << choice << "\n";
        if(choice <= 0 || choice >= 9){
            std::cout << "Invalid choice.\n";
        }
        if(choice==1){ //adds node to front
            std::cout << "Input a value to add: ";
            std::cin >> value;
            std::cout << "Added " << value << " to the list\n";
            linkedList->addFront(value);
        }
        if(choice==2){ //adds node to back
            std::cout << "Input a value to add: ";
            std::cin >> value;
            std::cout << "Added " << value << " to the list\n";
            linkedList->addBack(value);
        }
        if(choice==3){ //removes first item from list
            linkedList->removeFront();
        }
        if(choice==4){ //removes last item in list
            linkedList->removeBack();
        }
        if(choice==5){ //prints out whole list
            std::cout << "Printing List:\n";
            linkedList->printList();
        }
        if(choice==6){ //searches for item in list
            std::cout << "Enter a value to search for: ";
            std::cin >> value;
            std::cout << "Searching for " << value << "...\n";
            bool isFound=linkedList -> search(value);
            if(isFound){
                std::cout << value << " is in the list!\n";
            }
            else{
                std::cout << value << " is not in the list! Oh no!\n";
            }
        }
        if(choice==7){ //exits program
            isRunning=false;
            std::cout << "Exiting...Goodbye!\n";
        }
        if(choice==8){ //runs through all tests
            Test myTester(std::cout);
            myTester.runTests();
        }
    }
    delete linkedList;
    linkedList=nullptr;
    return(0);
}
