/*
@file: main.cpp
@author: Hamza Hameed
@date: November 2, 2015
@brief: main for program, takes in arguments
*/
#include <iostream>
#include "Sorts.h"
#include "SortDriver.h"
//#include "NumberFileGenerator.h"
#include "NumberFileDriver.h"
#include "Test.h"
int main(int argc, char** argv){
    Test myTester(std::cout);
    myTester.runTests();
    std::string option=argv[1];
    if(option=="-create"){
        NumberFileDriver::run(argc, argv);
    }
    else if(option=="-sort"){
        SortDriver::run(argc, argv);
    }

    return(0);
}
