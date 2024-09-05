/*
@file: NumberFileDriver.h
@author: Hamza Hameed
@date: November 2, 2015
@brief: Helps with NumberFileGenerator
*/
#ifndef NUMBER_FILE_DRIVER_H
#define NUMBER_FILE_DRIVER_H
#include <string>
#include <iostream>
#include "NumberFileGenerator.h"
class NumberFileDriver{

    public:
    /*
    @pre: arguments are valid
    @post: a number file is created following arguments, else help menu is printed
    @return: none
    */
    static void run(int argc, char** argv);
    /*
    @pre: none
    @post: prints help menu
    @return: none
    */
    static void printHelpMenu();

    private:
    /*
    @pre: none
    @post: prints menu to help user use NumberFileGenerator
    @return: true if option is valid
    */
    static bool isValidOption(std::string option);

};
#endif
