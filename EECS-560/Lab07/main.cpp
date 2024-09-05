#include <iostream>
#include <fstream>
#include "min5heap.h"
#include "max5heap.h"

void menu(){
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
              << "\nPlease choose one of the following commands:\n"
              << "1- Insert\n"
              << "2- DeleteMin\n"
              << "3- FindMin\n"
              << "4- FindMax\n"
              << "5- DeleteMax\n"
              << "6- LevelOrder\n"
              << "7- Exit\n"
              << "> ";
}

int main(){
    int choice;
    int num;
    min5heap* minHeap = new min5heap;
    minHeap -> buildHeap();
    max5heap* maxHeap = new max5heap;
    maxHeap -> buildHeap();
    while(true){
        menu();
        std::cin >> choice;
        if(choice == 1){
            std::cout << "Enter a number to be inserted:\n";
            std::cin >> num;
            minHeap -> insert(num);
            maxHeap -> insert(num);
        }else if(choice == 2){
            minHeap -> deleteMin();
            maxHeap -> deleteMin();
        }else if(choice == 3){
            std::cout << "Min value is: " << minHeap -> findMin() << "\n";
        }else if(choice == 4){
            std::cout << "Max value is: " << maxHeap -> findMax() << "\n";
        }else if(choice == 5){
            minHeap -> deleteMax();
            maxHeap -> deleteMax();
        }else if(choice == 6){
            std::cout << "\nMin 5-Heap:";
            minHeap -> levelOrder();
            std::cout << "\nMax 5-Heap:";
            maxHeap -> levelOrder();
        }else if(choice == 7){
            std::cout << "Adios!\n";
            delete minHeap;
            delete maxHeap;
            return 0;
        }
    }
}
