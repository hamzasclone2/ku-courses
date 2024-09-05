/*
@file: Chicken.h
@author: Hamza Hameed
@date: October 19, 2015
@brief: Header file for chicken. More specialized FarmAnimal.
*/
#ifndef CHICKEN_H
#define CHICKEN_H
#include "FarmAnimal.h"
class Chicken: public FarmAnimal{
    protected:
    /*
    @pre: none
    @post: returns value for m_eggs
    @return: m_eggs
    */
    int getEggs() const;
    /*
    @pre: valid integer eggs
    @post: sets m_eggs to eggs
    @return: none
    */
    void setEggs(int eggs);
    int m_eggs;

    public:
    /*
    @pre: none
    @post: sets m_name and m_sound
    @return: none
    */
    Chicken();
};
#endif
