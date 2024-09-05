/*
@file: SortDriver.cpp
@author: Hamza Hameed
@date: November 2, 2015
@brief: deals with files and arrays
*/
#include "SortDriver.h"
void SortDriver::run(int argc, char** argv){
    std::string sortName=argv[2];
    std::string inFileName=argv[3];
    std::string outFileName=argv[4];
    std::ifstream input(inFileName);
    if(areParametersValid(sortName, inFileName)){
        std::ofstream myOutputFile(outFileName);
        int size=SortDriver::getFileCount(input);
        int* arr=SortDriver::createArray(input, size);
        double elapsed;
        std::cout << "Calculating sort timing information\n";
        if(sortName=="-bubble"){
            elapsed=Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
            myOutputFile << "bubble " << size << " " << elapsed;
        }
        else if(sortName=="-selection"){
            elapsed=Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
            myOutputFile << "selection " << size << " " << elapsed;
        }
        else if(sortName=="-insertion"){
            elapsed=Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);
            myOutputFile << "insertion " << size << " " << elapsed;
        }
        else if(sortName=="-quick"){
            elapsed=Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, size);
            myOutputFile << "quick " << size << " " << elapsed;
        }
        else if(sortName=="-quick3"){
            elapsed=Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, arr, size);
            myOutputFile << "quick3 " << size << " " << elapsed;
        }
        else if(sortName=="-merge"){
            elapsed=Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, size);
            myOutputFile << "selection " << size << " " << elapsed;
        }
        else if(sortName=="-all"){
            std::cout << "Didn't have time to finish the -all case. Sorry!\n";
        }
        std::cout << "Calculations finished. Results stored in " << outFileName << "\n"
                  << "Exiting...\n";

    }
}
void SortDriver::printHelpMenu(){
    std::cout << "\nSorting is done one of the following ways:\n\n"
			  << "./prog -sort -bubble inputFile outputFile\n"
			  << "./prog -sort -selection inputFile outputFile\n"
			  << "./prog -sort -insertion inputFile outputFile\n"
			  << "./prog -sort -quick inputFile outputFile\n"
			  << "./prog -sort -quick3 inputFile outputFile\n"
			  << "./prog -sort -merge inputFile outputFile\n"
			  << "./prog -sort -all inputFile outputFile\n"
			  << "Option explanations:\n"
			  << "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			  << "\t-selection to time selection sort and store all timing results in outputFile\n"
			  << "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			  << "\t-quick to time quick sort and store all timing results in outputFile\n"
			  << "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			  << "\t-merge to time merge sort  and store all timing results in outputFile\n"
			  << "\t-all to time all of the sorts and store all timing results in outputFile\n"
			  << "\tinputFile must be file created by a NumberFileGenerator\n"
			  << "\toutputFile must be to a valid path. It will hold the timing results\n";
}
bool SortDriver::isFileAccessible(std::string fileName){
    std::ifstream file(fileName);
    if(file.good()){
        return true;
    }
    else{
        return false;
    }
}
bool SortDriver::isSortValid(std::string sortParameter){
    if(sortParameter=="-bubble" || sortParameter=="-insertion"
    || sortParameter=="-selection" || sortParameter=="-selection"
    || sortParameter=="-merge" || sortParameter=="-quick"
    || sortParameter=="-quick3"){
        return true;
    }
    else{
        printHelpMenu();
        return false;
    }
}
bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName){
    if(isSortValid(sortName) && isFileAccessible(inputFileName)){
        return true;
    }
    else{
        return false;
    }
}
int SortDriver::getFileCount(std::ifstream& inputFile){
    std::ifstream& myInputFile(inputFile);
    int x;
    myInputFile >> x;
    return x;
}
int* SortDriver::createArray(std::ifstream& inputFile, int size){
    std::ifstream& myInputFile(inputFile);
    int* arr=new int[size];
    int extra;
    myInputFile >> extra;
    for(int i=0; i<size-1; i++){
        myInputFile >> arr[i];
    }
    return arr;
}
void SortDriver::copyArray(int original[], int copy[], int size){
    for(int i=0; i< size; i++){
        copy[i]=original[i];
    }
}
