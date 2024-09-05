/*
@file: SortDriver.h
@author: Hamza Hameed
@date: November 2, 2015
@brief: deals with files and arrays
*/
#ifndef SORT_DRIVER_H
#define SORT_DRIVER_H
#include <string>
#include <iostream>
#include <fstream>
#include "Sorts.h"
class SortDriver{

    public:
    /*
    @pre: arguments are valid
    @post:  A file is created with timing info on sorts
    @return: none
    */
    static void run(int argc, char** argv);
    /*
    @pre: none
    @post: prints out a help menu
    @return: none
    */
    static void printHelpMenu();

    private:
    /*
    @pre: valid string fileName
    @post: checks if file exists
    @return: true if it does, false otherwise
    */
    static bool isFileAccessible(std::string fileName);
    /*
    @pre: none
    @post: none
    @return: returns true if sort parameter matches a valid one
    */
    static bool isSortValid(std::string sortParameter);
    /*
    @pre: none
    @post: none
    @return: true if file specified exists and sot paramter is valid
    */
    static bool areParametersValid(std::string sortName, std::string inputFileName);
    /*
    @pre: the input file was created by NumberFileGenerator
    @post: the first line of the file is read in, containing the count
    @return: how many numbers are in the file
    */
    static int getFileCount(std::ifstream& inputFile);
    /*
    @pre: the input file was created by NumberFileGenerator, size was read in,
          and that size was correct
    @post: the remainder of input file numbers are read in, file is not closed
    @return: a pointer to a new array containg values from input file
    */
    static int* createArray(std::ifstream& inputFile, int size);
    /*
    @pre: original and copy are valid arrays of the correct size
    @post: all values from original are copied into copy
    @return: none
    */
    static void copyArray(int original[], int copy[], int size);
};
#endif
