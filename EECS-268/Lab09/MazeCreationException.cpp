/*
@author: Hamza Hameed
@file: MazeCreationException.cpp
@date: November 13, 2015
@brief: creates exceptions when using maze
*/
#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message):
std::runtime_error(message){

}
