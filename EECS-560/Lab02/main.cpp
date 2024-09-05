#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Hash.h"

//prints out the menu used throughout the program
void printMenu(){
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n";
    std::cout << "2- Delete\n";
    std::cout << "3- Find\n";
    std::cout << "4- Print\n";
    std::cout << "5- Exit\n";
    std::cout << "> ";
}

int main(){
    int choice;
    int num;

    Hash* hashTable = new Hash();

    //sets up the initial hash table by using text file
    int data;
    std::ifstream file;
    file.open("data.txt");
    int burn;
    file >> burn; //skips over the size
    while(file >> data){
        if(hashTable -> find(data) == false){
            hashTable -> insert(data);
        }
    }
    std::cout << "\nHash table made from data.txt\n";

    while(true){
        printMenu();
        std::cin >> choice;
        //insert
        if (choice == 1){
            std::cout << "\nEnter a number to insert into the hash table.\n";
            std::cin >> num;
            if(hashTable -> find(num)){ //if num is found then don't insert
                std::cout << "\nEntered number already exists in the hash table.\n";
            }else{ //else insert
                std:: cout << "\nEntered number has been added into the hash table.\n";
                hashTable -> insert(num);
            }
        //delete
        }else if (choice == 2){
            std::cout << "\nEnter a number to be deleted from the hash table.\n";
            std::cin >> num;
            if(hashTable -> find(num)){ //if num is found then delete
                hashTable -> erase(num);
                std::cout << "\nEntered number has been deleted from the hash table.\n";
            }else{ //else number was not found so do nothing
                std::cout << "\nEntered number was not found in the hash table.\n";
            }
        //find
        }else if (choice == 3){
            std::cout << "\nEnter a number to be found:\n";
            std::cin >> num;
            if(hashTable -> find(num)){ //if num is found
                std::cout << "\nEntered number was found in the hash table.\n";
            }else{ //num was not found
                std::cout << "\nEntered number was not found in the hash table.\n";
            }
        //print
        }else if (choice == 4){
            hashTable -> print();
        //exit
        }else if (choice == 5){
            std::cout << "\nBye!\n";
            delete hashTable;
            return(0);
        }
    }
}
