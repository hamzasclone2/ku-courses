/*
@file: main.cpp
@author: Hamza Hameed
@date: October 21, 2015
@brief: Gets sort choice, array size, min, and max from user
        Also times how long sorts take
*/
#include <iostream>
#include "Sorts.h"
#include "Test.h"

void printMenu(){
	std::cout 	<< "\n\nSelect a sort:\n"
			    << "1) Bubble Sort\n"
			    << "2) Insertion Sort\n"
			    << "3) Selection Sort\n"
			    << "4) Bogo Sort (use only with very small arrays!)\n"
                << "5) Run Tests\n"
			    << "Enter choice: ";
}

void printArray(int arr[], int size, char print){
    if(print=='y'){
        std::cout << "\n[";
        for(int i=0; i<size; i++){
            std::cout << arr[i];
            if(i!=size-1){
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
}

int main(){
    int choice=0;
    int size=0;
    int min=0;
    int max=0;
    char quit='\0';
    char print='\0';
		int* arr;
		double elapsed;
    do{
        printMenu();
        std::cin >> choice;
        if(choice != 5){
            std::cout << "Input a size for the random array: ";
            std::cin >> size;
            std::cout << "Input a lower bound on the range of random numbers: ";
            std::cin >> min;
            std::cout << "Input an upper bound on the range of random numbers: ";
            std::cin >> max;
            arr=Sorts<int>::createTestArray(size, min, max);
            std::cout << "Do you want to print the unsorted array? (y/n): ";
            std::cin >> print;
            print=tolower(print);
            printArray(arr, size, print);
            std::cout << "\nSorting with ";
            if(choice==1){
                std::cout << "Bubble Sort...\n";
                std::cout << "\nDo you want to print the sorted array? (y/n): ";
                std::cin >> print;
								elapsed=Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
            }
            else if(choice==2){
                std::cout << "Insertion Sort...\n";
                std::cout << "\nDo you want to print the sorted array? (y/n): ";
                std::cin >> print;
                elapsed=Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);
            }
            else if(choice==3){
                std::cout << "Selection Sort...\n";
                std::cout << "\nDo you want to print the sorted array? (y/n): ";
                std::cin >> print;
                elapsed=Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
            }
            else if(choice==4){
                std::cout << "Bogo Sort...\n";
                std::cout << "\nDo you want to print the sorted array? (y/n): ";
                std::cin >> print;
								elapsed=Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
            }
						printArray(arr, size, print);
						std::cout << "\n" << size << " numbers were sorted in " << elapsed << " seconds\n";
        }
        else
            Test myTester(std::cout);
            myTester.runTests();
        }
        std::cout << "Do you want to quit? (y/n): ";
        std::cin >> quit;
        quit=tolower(quit);
				delete arr;
    }while(quit!='y');
    return(0);
}
