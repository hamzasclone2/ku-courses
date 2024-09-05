/*
@file: NumberFileGenerator.h
@author: Hamza Hameed
@date: November 2, 2015
@brief: generates number file
*/
#ifndef NUMBER_FILE_GENERATOR_H
#define NUMBER_FILE_GENERATOR_H
#include <string>
#include <fstream>
#include <ctime>
#include <random>
#include <iostream>
class NumberFileGenerator{

    public:
    /*
    @pre: fileName is a valid filename, amount>0
    @post: a file is created with the amount of numbers in ascending order
    @return: none
    */
    static void ascending(std::string fileName, int amount);
    /*
    @pre: fileName is a valid filename, amount>0
    @post: a file is created with the amount of numbers in descending order
    @return: none
    */
    static void descending(std::string fileName, int amount);
    /*
    @pre: fileName is a valid filename, amount>0
    @post: a file is created with specified amount of numbers. All #'s are all
           random and fall withing min and max. The amount of numbers is first
           entry in file
    @return: none
    */
    static void random(std::string fileName, int amount, int min, int max);
    /*
    @pre: fileName is a valid filename, amount>0
    @post: a file is created with a single number, specified by value, amount of
           times. Amount of numbers in file is first entry
    @return: none
    */
    static void singleValue(std::string fileName, int amount, int value);

};
#endif
