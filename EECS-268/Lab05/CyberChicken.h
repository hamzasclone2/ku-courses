/*
@file: CyberChicken.h
@author: Hamza Hameed
@date: October 19, 2015
@brief: Header file for CyberChicken class. More specialized Chicken.
*/
#ifndef CYBER_CHICKEN_H
#define CYBER_CHICKEN_H
#include "Chicken.h"
class CyberChicken: public Chicken{
    public:
    /*
    @pre: none
    @post: sets m_name and m_sound
    @return: none
    */
    CyberChicken();
    /*
    @pre: none
    @post: returns m_eggs
    @return: m_eggs
    */
    int getCyberEggs() const;
    /*
    @pre: valid integer eggs
    @post: sets m_eggs to eggs
    @return: none
    */
    void setCyberEggs(int eggs);
};
#endif
