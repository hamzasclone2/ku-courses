/*
@file: Cow.h
@author: Hamza Hameed
@date: October 19, 2015
@brief: Header file for cow class. More specialized FarmAnimal.
*/
#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"
class Cow: public FarmAnimal{
    protected:

    double m_milkProduced;

    public:
    /*
    @pre: none
    @post: sets m_name and m_sound
    @return:
    */
    Cow();
    /*
    @pre: none
    @post: returns m_milkProduced
    @return: m_milkProduced
    */
    double getMilkProduced() const;
    /*
    @pre: valid double gallons
    @post: sets m_milkProduced to gallons
    @return: none
    */
    void setMilkProduced(double gallons);
};
#endif
