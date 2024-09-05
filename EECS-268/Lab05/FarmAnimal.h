/*
@file: FarmAnimal.h
@author: Hamza Hameed
@date: October 19, 2015
@brief: Base class for all the animals.
*/
#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H
#include <string>
class FarmAnimal{
    protected:
    std::string m_name;
    std::string m_sound;
    public:
    /*
    @pre: none
    @post: sets m_name and m_sound
    @return: none
    */
    FarmAnimal();
    /*
    @pre: none
    @post: returns m_name
    @return: m_name
    */
    std::string getName() const;
    /*
    @pre: valid string name
    @post: sets m_name to name
    @return: none
    */
    void setName(std::string name);
    /*
    @pre: none
    @post: returns m_sound
    @return: m_sound
    */
    std::string getSound() const;
    /*
    @pre: valid string sound
    @post: sets m_sound to sound
    @return: none
    */
    void setSound(std::string sound);
};
#endif
