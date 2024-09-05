/*
@file: AnimalPen.h
@author: Hamza Hameed
@date: October 19, 2015
@brief: Header file for AnimalPen. More specialized version of Stack.
*/
#ifndef ANIMALPEN_H
#define ANIMALPEN_H
#include "Stack.h"
#include "FarmAnimal.h"
class AnimalPen: public Stack<FarmAnimal*>{
    public:
    /*
    @pre: none
    @post: none, empty constructor
    @return: none
    */
    AnimalPen();
    /*
    @pre: There exists an AnimalPen pointer
    @post: destructs pointer
    @return: none
    */
    ~AnimalPen();
    /*
    @pre: valid FarmAnimal pointer animal
    @post: adds animal to the pen
    @return: none
    */
    void addAnimal(FarmAnimal* animal);
    /*
    @pre: none
    @post: returns most recent animal added to pen
    @return: most recent animal made
    */
    FarmAnimal* peekAtNextAnimal();
    /*
    @pre: none
    @post: deletes most recent animal added to pen
    @return: none
    */
    void releaseAnimal();
    /*
    @pre: none
    @post: checks if pen is empty
    @return: true if it is, false otherwise
    */
    bool isPenEmpty();
};
#endif
