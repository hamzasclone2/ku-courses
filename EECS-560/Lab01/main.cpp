#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"

//prints out the menu used throughout the program
void printMenu(){
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n";
    std::cout << "2- Delete\n";
    std::cout << "3- Find\n";
    std::cout << "4- Print\n";
    std::cout << "5- Exit\n";
    std::cout << "> " ;
}

int main(){
    int choice;
    int num;
    List* list = new List();

    //sets up the initial list by using text file
    int data;
    std::ifstream file;
    file.open("data.txt");
    while(file >> data){
        list -> insert(data);
    }
    std::cout << "\nList made from data.txt\n";

    while(true){
        printMenu();
        std::cin >> choice;
        //insert
        if (choice == 1){
            std::cout << "\nEnter a number to be inserted into the list:\n";
            std::cin >> num;
            //if num is not found in the list then insert
            if(list -> find(num) == nullptr){
                list -> insert(num);
                std::cout << "\nEntered number has been inserted into the list.\n";
            }else{ //else the number already exists
                std::cout << "\nEntered number already exists in the list.\n";
            }
        //delete
        }else if (choice == 2){
            std::cout << "\nEnter a number to be deleted from the list:\n";
            std::cin>> num;
            //if list is found then delete
            if(list -> find(num)){
                list -> erase(num);
                std::cout << "\nEntered number has been deleted from the list.\n";
            }else{ //else number was not in the list
                std::cout << "\nEntered number was not found in the list.\n";
            }
        //find
        }else if (choice == 3){
            std::cout << "\nEnter a number to be found:\n";
            std::cin >> num;
            //if number is not found
            if(list -> find(num) == nullptr){
                std::cout << "\nEntered number was not found in the list.\n";
            }else{ //number was found
                std::cout << "\nEntered number was found in the list.\n";
            }
        //print
        }else if (choice == 4){
            list -> print();
        //exit
        }else if (choice == 5){
            list -> ~List();
            return(0);
        }
    }
}
