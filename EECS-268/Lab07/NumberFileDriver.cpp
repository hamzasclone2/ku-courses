/*
@file: NumberFileDriver.cpp
@author: Hamza Hameed
@date: November 2, 2015
@brief: Helps with NumberFileGenerator
*/
#include "NumberFileDriver.h"
void NumberFileDriver::run(int argc, char** argv){
    std::string option=argv[2];
    std::string filename=argv[3];
    int amount=atoi(argv[4]);
    if(isValidOption(option)){
        if(argc==5){
            if(option=="-a"){
                NumberFileGenerator::ascending(filename, amount);
            }
            else if(option=="-d"){
                NumberFileGenerator::descending(filename, amount);
            }
        }
        else if(argc==6){
            if(option=="-s"){
                int value=atoi(argv[5]);
                NumberFileGenerator::singleValue(filename, amount, value);
            }
        }
        else if(argc==7){
            if(option=="-r"){
                int min=atoi(argv[5]);
                int max=atoi(argv[6]);
                NumberFileGenerator::random(filename, amount, min, max);
            }
        }
    }
}
void NumberFileDriver::printHelpMenu(){
    std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			  << "./prog -create -a filename amount\n"
			  << "./prog -create -d filename amount\n"
			  << "./prog -create -s filename amount value\n"
			  << "./prog -create -r filename amount min max\n"
			  << "Option explanations:\n"
			  << "\t-a for ascending\n"
			  << "\t-d for descending\n"
			  << "\t-s for a single value\n"
			  << "\t-r for random values\n"
			  << "\tfilename is the ouput file name\n"
			  << "\tamount is the amount of random numbers to place in the file\n"
			  << "\tvalue is the single number that will be written to file in -s mode\n"
			  << "\tmin is the low end of the range of random numbers\n"
			  << "\tmax is the high end (non-inclusive) of the range of random numbers\n";
}
bool NumberFileDriver::isValidOption(std::string option){
    if(option=="-a" || option=="-d" || option=="-s" || option=="-r"){
        return true;
    }
    else{
        printHelpMenu();
        return false;
    }
}
