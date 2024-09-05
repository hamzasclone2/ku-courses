#include <iostream>
#include "leftistHeap.h"
#include "skewHeap.h"

void printMenu(){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << "Please choose one of the following commands:\n"
              << "1- Insert\n"
              << "2- Delete Min\n"
              << "3- PreOrder\n"
              << "4- InOrder\n"
              << "5- LevelOrder\n"
              << "6- Exit\n";
}

int main(){
    int choice;
    int num;

    leftistHeap* l_heap = new leftistHeap();
    skewHeap* s_heap = new skewHeap();
    l_heap -> buildHeap();
    s_heap -> buildHeap();

    while(true){
        printMenu();
        std::cin >> choice;
        if(choice == 1){
            std::cout << "Insert a value: ";
            std::cin >> num;
            l_heap -> insert(num);
            s_heap -> insert(num);
        }else if(choice == 2){
            l_heap -> deleteMin();
            s_heap -> deleteMin();
        }else if(choice == 3){
            std::cout << "Leftist Heap:\n";
            l_heap -> print("pre");
            std::cout << "\n";
            std::cout << "Skew Heap:\n";
            s_heap -> print("pre");
            std::cout << "\n";
        }else if(choice == 4){
            std::cout << "Leftist Heap:\n";
            l_heap -> print("in");
            std::cout << "\n";
            std::cout << "Skew Heap:\n";
            s_heap -> print("in");
            std::cout << "\n";
        }else if(choice == 5){
            std::cout << "Leftist Heap:\n";
            l_heap -> print("level");
            std::cout << "\n";
            std::cout << "Skew Heap:\n";
            s_heap -> print("level");
            std::cout << "\n";
        }else if(choice == 6){
            l_heap -> ~leftistHeap();
            s_heap -> ~skewHeap();
            return 0;
        }
    }
}
