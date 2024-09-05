/*
@file: Cow.h
@author: Hamza Hameed
@date: October 19, 2015
@brief: Gives cow a name and sound, and sets milk produced that user provides
*/
#include "Cow.h"
Cow::Cow(){
    m_name="Cow";
    m_sound="Moo";
}
double Cow::getMilkProduced() const{
    return m_milkProduced;
}
void Cow::setMilkProduced(double gallons){
    if(gallons>0){
        m_milkProduced=gallons;
    }
    else{
        m_milkProduced=0;
    }
}
