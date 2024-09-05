/*
@file: CyberChicken.cpp
@author: Hamza Hameed
@date: October 19, 2015
@brief: Gets set a name and sound, and number of eggs produced based on user
        input
*/
#include "CyberChicken.h"
CyberChicken::CyberChicken(){
    m_name="CyberChicken";
    m_sound="Resistance is futile";
}
int CyberChicken::getCyberEggs() const{
    return m_eggs;
}
void CyberChicken::setCyberEggs(int eggs){
    m_eggs=eggs;
}
