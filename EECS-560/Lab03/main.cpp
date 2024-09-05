#include <iostream>
#include <fstream>
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

int main(int argc, char *argv[]){
    int choice;
    int num;
    Hash* hashTable = new Hash;

    int data;
    std::ifstream file;
    file.open(argv[1]);
    while(file >> data){
        if(hashTable -> qp_find(data) == -1){
            hashTable -> qp_insert(data);
        }
        if(hashTable -> dh_find(data) == -1){
            hashTable -> dh_insert(data);
        }
    }
    if(argc > 1){
        std::cout << "\nHash tables made from text file.\n";
    }
    std::cout << "\nLoad factor of hash table with quadratic probing is "
              << hashTable -> qp_loadFactor() << ".\n";
    std::cout << "Load factor of hash table with double hashing is "
              << hashTable -> dh_loadFactor() << ".";

    while(true){
        printMenu();
        std::cin >> choice;
        if(choice == 1){ //insert
            std::cout << "Enter a number to be inserted:";
            std::cin >> num;
            if(hashTable -> qp_find(num) != -1){
                std::cout << num << " already exists in the hash table with quadratic probing.\n";
            }else{
                if(hashTable -> qp_insert(num) == false){
                    std::cout << "\nFailed to insert " << num << " into hash table with quadratic probing.\n";
                }else{
                    std::cout << "\nSuccessfully inserted " << num << " into hash table with quadratic probing.\n";
                }
            }
            if(hashTable -> dh_find(num) != -1){
                std::cout << num << " already exists in the hash table with double hashing.\n";
            }else{
                if(hashTable -> dh_insert(num) == false){
                    std::cout << "Failed to insert " << num << " into hash table with double hashing.\n";
                }else{
                    std::cout << "Successfully inserted " << num << " into hash table with double hashing.\n";
                }
            }
            std::cout << "\nLoad factor of hash table with quadratic probing is "
                      << hashTable -> qp_loadFactor() << ".\n";
            std::cout << "Load factor of hash table with double hashing is "
                      << hashTable -> dh_loadFactor() << ".";
        }else if(choice == 2){ //delete
            std::cout << "Enter a number to be deleted:";
            std::cin >> num;
            if(hashTable -> qp_erase(num)){
                std::cout << num <<  " was erased from the hash table with quadratic probing.\n";
            }else{
                std::cout << num << " was not found in the hash table with quadratic probing.\n";
            }
            if(hashTable -> dh_erase(num)){
                std::cout << num << " was erased from the hash table with double hashing.\n";
            }else{
                std::cout << num << " was not found in the hash table with double hashing.\n";
            }
            std::cout << "\nLoad factor of hash table with quadratic probing is "
                      << hashTable -> qp_loadFactor() << ".\n";
            std::cout << "Load factor of hash table with double hashing is "
                      << hashTable -> dh_loadFactor() << ".";
        }else if(choice == 3){ //find
            std::cout << "Enter a number to be found:";
            std::cin >> num;
            if(hashTable ->qp_find(num) != -1){
                std::cout << num << " exists in the hash table with quadratic probing.";
            }else{
                std::cout << num << " does not exist in the hash table with quadratic probing.";
            }
            std::cout << "\n";
            if(hashTable ->dh_find(num) != -1){
                std::cout << num << " exists in the hash table with double hashing.";
            }else{
                std::cout << num << " does not exist in the hash table with double hashing.";
            }
        }else if(choice == 4){ //print
            hashTable -> print();
        }else if(choice == 5){ //exit
            std::cout << "Bye!\n";
            delete hashTable;
            return(0);
        }
    }
}
