/*
@file: main.cpp
@author: Hamza Hameed
@date: November 4, 2015
@brief: serves as driver, allowing for interaction with BST
*/
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <climits>
#include <vector>
#include "Node.h"
#include "BSTI.h"
#include "BinarySearchTree.h"
#include "Test.h"
void printMenu(){
    std::cout << "\nInput a selection\n"
              << "1) Add more values to original tree\n"
              << "2) Copy the original tree\n"
              << "3) Delete the original tree (one time only)\n"
              << "4) Print original tree\n"
              << "5) Print copy\n"
              << "6) Search original tree\n"
              << "7) Search copy\n"
              << "8) Exit\n"
              << "9) Run Tests\n"
              << "Your choice: ";
}
void addBatch(BinarySearchTree<int>* BST, int num){
    int randomNumber;
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
    for(int i=0; i < num; i++){
        randomNumber=distribution(generator);
        BST -> add(randomNumber);
    }
}
int main(int argc, char** argv){
    BinarySearchTree<int>* BST = new BinarySearchTree<int>;
    BSTI<int>* copy = new BinarySearchTree<int>;
    Test tester;
    std::string option = argv[1];
    bool isRunning = true;
    int choice;
    if(option == "-test"){
        tester.runTests();
    }
    else if(option == "-nodes"){
        int num = atoi(argv[2]);
        addBatch(BST, num);
    }
    while(isRunning){
        printMenu();
        std::cin >> choice;
        if(choice == 1){
            if(BST ==  nullptr){
                std::cout << "\nOriginal does not exist anymore. Can't add values.";
            }
            else{
                std::cout << "\nChoose one:\n"
                          << "1) Add another random batch of values\n"
                          << "2) Add a specific value\n"
                          << "Choice: ";
                std::cin >> choice;
                if(choice ==  1){
                    int amount;
                    std::cout << "How many random values would you like to add?: ";
                    std::cin >> amount;
                    addBatch(BST, amount);
                    std::cout << amount << " random values added!\n";
                }
                else if(choice == 2){
                    int value;
                    std::cout << "What value would you like to add?: ";
                    std::cin >> value;
                    BST -> add(value);
                    std::cout << "\n" << value << " added to the tree!\n";
                }
            }
        }
        else if(choice == 2){
            copy = BST -> clone();
            std::cout << "\nClone created!\n";
        }
        else if(choice == 3){
            if(BST == nullptr){
                std::cout << "\nOriginal does not exist anymore.\n";
            }
            else{
                delete BST;
                BST = nullptr;
                std::cout << "\nOriginal tree deleted!\n";
            }
        }
        else if(choice == 4){
            if(BST != nullptr){
                std::cout << "\nChoose a type of order:\n"
                          << "1) Pre-Order\n"
                          << "2) In-Order\n"
                          << "3) Post-Order\n"
                          << "Choice: ";
                std::cin >> choice;
                if(choice == 1){
                    std::cout << "\n";
                    BST -> printTree(PRE_ORDER);
                    std::cout << "\n";
                }
                else if(choice == 2){
                    std::cout << "\n";
                    BST -> printTree(IN_ORDER);
                    std::cout << "\n";
                }
                else if(choice == 3){
                    std::cout << "\n";
                    BST -> printTree(POST_ORDER);
                    std::cout << "\n";
                }
            }
            else{
                std::cout << "\nOriginal does not exist anymore.\n";
            }
        }
        else if(choice == 5){
            std::cout << "\nChoose a type of order:\n"
                      << "1) Pre-Order\n"
                      << "2) In-Order\n"
                      << "3) Post-Order\n"
                      << "Choice: ";
            std::cin >> choice;
            if(choice == 1){
                std::cout << "\n";
                copy -> printTree(PRE_ORDER);
                std::cout << "\n";
            }
            else if(choice == 2){
                std::cout << "\n";
                copy -> printTree(IN_ORDER);
                std::cout << "\n";
            }
            else if(choice == 3){
                std::cout << "\n";
                copy -> printTree(POST_ORDER);
                std::cout << "\n";
            }
        }
        else if(choice == 6){
            int value;
            std::cout << "What value would you like to search for?: ";
            std::cin >> value;
            if(BST == nullptr){
                std::cout << "\nOriginal does not exist anymore.\n";
            }
            else{
                if(BST -> search(value)){
                    std::cout << "\nThe value " << value << " is in the tree!\n";
                }
                else{
                    std::cout << "\nThe value " << value << " is not in the tree!\n";
                }
            }
        }
        else if(choice == 7){
            int value;
            std::cout << "What value would you like to search for?: ";
            std::cin >> value;
            if(copy -> search(value)){
                std::cout << "\nThe value " << value << " is in the clone!\n";
            }
            else{
                std::cout << "\nThe value " << value << " is not in the clone!\n";
            }
        }
        else if(choice == 8){
            isRunning = false;
            std::cout << "Exiting...\n";
        }
        else if(choice == 9){
            tester.runTests();
        }
    }
    delete BST;
    delete copy;
    return(0);
}
