#include <iostream>
#include <fstream>
#include "BST.h"

void printMenu(){
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << "Please choose one of the following commands:\n"
              << "1-  Insert\n"
              << "2-  DeleteMin\n"
              << "3-  DeleteMax\n"
              << "4-  Delete\n"
              << "5-  FindMin\n"
              << "6-  FindMax\n"
              << "7-  Preorder\n"
              << "8-  Inorder\n"
              << "9-  Postorder\n"
              << "10- Exit\n"
              << "> ";
}

int main(int argc, char* argv[]){
    BST* bst = new BST();
    int choice;
    int num;

    if(argc > 1){
        std::ifstream file;
        file.open(argv[1]);
        int data;
        while(file >> data){
            bst -> insert(data);
        }
        std::cout << "\nBinary Search Tree made from data file.\n";
    }

    while(true){
        printMenu();
        std::cin >> choice;
        if(choice == 1){ //insert
            std::cout << "Enter the number to be inserted:\n";
            std::cin >> num;
            bst -> insert(num);
        }else if(choice == 2){ //deleteMin
            std::cout << bst -> findMin() << " has been deleted.\n";
            bst -> deleteMin();
        }else if(choice == 3){ //deleteMax
            std::cout << bst -> findMax() << " has been deleted.\n";
            bst -> deleteMax();
        }else if(choice == 4){ //delete value
            std::cout << "Enter the number to be deleted:\n";
            std::cin >> num;
        }else if(choice == 5){ //findMin
            std::cout << "The minimum value is " << bst -> findMin() << ".\n";
        }else if(choice == 6){ //findMax
            std::cout << "The maximum value is " << bst -> findMax() << ".\n";
        }else if(choice == 7){ //preorder
            std::cout << "Preorder: ";
            bst -> print("preorder");
        }else if(choice == 8){ //inorder
            std::cout << "Inorder: ";
            bst -> print("inorder");
        }else if(choice == 9){ //postorder
            std::cout << "Postorder: ";
            bst -> print("postorder");
        }else if(choice == 10){ //exit
            std::cout << "Bye!\n";
            return(0);
        }
    }
}
