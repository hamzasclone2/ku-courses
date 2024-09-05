/*
@file: AnimalPen.cpp
@author: Hamza Hameed
@date: October 19th, 2015
@brief: Uses Stack to do basically the same thing, but with animals
*/
#include "AnimalPen.h"
AnimalPen::AnimalPen(){
    //empty!!!
}
AnimalPen::~AnimalPen(){
    while(!isPenEmpty()){
        releaseAnimal();
    }
}
void AnimalPen::addAnimal(FarmAnimal* animal){
    push(animal);
}
FarmAnimal* AnimalPen::peekAtNextAnimal(){
    return peek();
}
void AnimalPen::releaseAnimal(){
    pop();
}
bool AnimalPen::isPenEmpty(){
    return isEmpty();
}
