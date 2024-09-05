#include "twoThreeTree.h"
#include <fstream>

void menu(){
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << "Please choose one of the following commands:\n"
              << "1- Insert\n"
              << "2- DeleteMin\n"
              << "3- DeleteMax\n"
              << "4- FindMin\n"
              << "5- FindMax\n"
              << "6- Find\n"
              << "7- Delete\n"
              << "8- Level Order\n"
              << "9- Exit\n"
              << "> ";
}

int main(int argc, char* argv[]){
    twoThreeTree* tree = new twoThreeTree();
    int choice;
    int num;

    if(argc > 1){
        std::ifstream file;
        file.open(argv[1]);
        int data;
        while(file >> data){
            if(tree -> find(data)){
                //do nothing
            }else{
                tree -> insert(data);
            }
        }
        std::cout << "\n2-3 Tree made from data file.\n";
    }

    while(true){
        menu();
        std::cin >> choice;
        if(choice == 1){
            std::cout << "Enter a number to be inserted:\n";
            std::cin >> num;
            if(tree -> find(num)){
                std::cout << "That value already exists in the tree.\n";
            }else{
                tree -> insert(num);
            }
        }else if(choice == 2){
            tree -> deleteMin();
        }else if(choice == 3){
            tree -> deleteMax();
        }else if(choice == 4){
            std::cout << "\n" << tree -> findMin() << " is the minimum value in the tree.\n";
        }else if(choice == 5){
            std::cout << "\n" << tree -> findMax() << " is the maximum value in the tree.\n";
        }else if(choice == 6){
            std::cout << "Enter a number to be found:\n";
            std::cin >> num;
            if(tree -> find(num)){
                std::cout << num << " exists in the tree.\n";
            }else{
                std::cout << num << " was not found in the tree.\n";
            }
        }else if(choice == 7){
            std::cout << "Enter a number to be deleted:\n";
            std::cin >> num;
            tree -> erase(num);
        }else if(choice == 8){
            tree -> levelOrder();
        }else if(choice == 9){
            std::cout << "Adios!\n";
            return(0);
        }
    }
}
