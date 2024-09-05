#include "minMax.h"
#include "maxMin.h"
#include <iostream>

void menu(){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << "Please choose one of the following commands:\n"
              << "1- Insert\n"
              << "2- Delete Min\n"
              << "3- Find Min\n"
              << "4- Find Max\n"
              << "5- Delete Max\n"
              << "6- Level Order\n"
              << "7- Exit\n"
              << ">";
}

int main(int argc, char* argv[]){
    std::string s = argv[1];
    if(argc < 2 || (s != "minmax" && s != "maxmin")){
        std::cerr << "\nError! Run program like ./lab08 minmax or ./lab08 maxmin\n\n";
        return 0;
    }
    int choice;
    int num;
    minMax* minMaxHeap = new minMax;
    maxMin* maxMinHeap = new maxMin;
    minMaxHeap -> buildHeap();
    maxMinHeap -> buildHeap();

    while(true){
        menu();
        std::cin >> choice;
        if(choice == 1){
            std::cout << "Enter a value to be inserted:\n";
            std::cin >> num;
            minMaxHeap -> insert(num);
            maxMinHeap -> insert(num);
        }else if(choice == 2){
            minMaxHeap -> deleteMin();
            maxMinHeap -> deleteMin();
        }else if(choice == 3){
            if(s == "minmax"){
                std::cout << "Min value is: " << minMaxHeap -> findMin() << "\n";
            }else if(s == "maxmin"){
                std::cout << "Min value is: " << maxMinHeap -> findMin() << "\n";
            }
        }else if(choice == 4){
            if(s == "minmax"){
                std::cout << "Max value is: " << minMaxHeap -> findMax() << "\n";
            }else if(s == "maxmin"){
                std::cout << "Max value is: " << maxMinHeap -> findMax() << "\n";
            }
        }else if(choice == 5){
            minMaxHeap -> deleteMax();
            maxMinHeap -> deleteMax();
        }else if(choice == 6){
            if(s == "minmax"){
                minMaxHeap -> levelOrder();
            }else if(s == "maxmin"){
                maxMinHeap -> levelOrder();
            }
        }else if(choice == 7){
            std::cout << "Goodbye forever!\n";
            delete minMaxHeap;
            return 0;
        }
    }
}
