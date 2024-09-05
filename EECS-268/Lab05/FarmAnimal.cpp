/*
@file: FarmAnimal.cpp
@author: Hamza Hameed
@date: October 19, 2015
@brief: Gets name and sound for each animal.
*/
#include "FarmAnimal.h"
FarmAnimal::FarmAnimal(){
    m_name="unset";
    m_sound="unset";
}
std::string FarmAnimal::getName() const{
    return m_name;
}
void FarmAnimal::setName(std::string name){
    m_name=name;
}
std::string FarmAnimal::getSound() const{
    return m_sound;
}
void FarmAnimal::setSound(std::string sound){
    m_sound=sound;
}
