/*
@file: Chick.cpp
@author: Hamza Hameed
@date: October 19, 2015
@brief: Extends from FarmAnimal. Doesn't do much besides allow CyberChicken
        to inherit from it.
*/
#include "Chicken.h"
Chicken::Chicken(){
    m_name="Chicken";
    m_sound="Cluck";
}
int Chicken::getEggs() const{
    return m_eggs;
}
void Chicken::setEggs(int eggs){
    m_eggs=eggs;
}
