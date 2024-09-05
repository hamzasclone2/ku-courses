/*
@file: NumberFileGenerator.cpp
@author: Hamza Hameed
@date: November 2, 2015
@brief: generates number file
*/
#include "NumberFileGenerator.h"
void NumberFileGenerator::ascending(std::string fileName, int amount){
    std::ofstream myOutputFile(fileName);
    myOutputFile << amount << "\n";
    for(int i=0; i<amount; i++){
        myOutputFile << i;
        if(i!=amount-1){
            myOutputFile << "\n";
        }
    }
    std::cout << "\n" << amount << " numbers stored in " << fileName << "\n";
}
void NumberFileGenerator::descending(std::string fileName, int amount){
    std::ofstream myOutputFile(fileName);
    myOutputFile << amount << "\n";
    for(int i=amount; i>0; i--){
        myOutputFile << i;
        if(i!=1){
            myOutputFile << "\n";
        }
    }
    std::cout << "\n" << amount << " numbers stored in " << fileName << "\n";
}
void NumberFileGenerator::random(std::string fileName, int amount, int min, int max){
    std::ofstream myOutputFile(fileName);
    myOutputFile << amount << "\n";
    int randomNumber;
    int* array=new int[amount];
    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min, max);
    for(int i=0; i<amount; i++){
        randomNumber=distribution(generator);
        array[i]=randomNumber;
    }
    for(int i=0; i<amount; i++){
        myOutputFile << array[i];
        if(i!=amount-1){
            myOutputFile << "\n";
        }
    }
    delete[] array;
    std::cout << "\n" << amount << " numbers stored in " << fileName << "\n";
}
void NumberFileGenerator::singleValue(std::string fileName, int amount, int value){
    std::ofstream myOutputFile(fileName);
    myOutputFile << amount << "\n";
    for(int i=0; i<amount; i++){
        myOutputFile << value;
        if(i!=amount-1){
            myOutputFile << "\n";
        }
    }
    std::cout << "\n" << amount << " numbers stored in " << fileName << "\n";
}
