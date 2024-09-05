/*
@author: Hamza Hameed
@file: MazeCreationException.h
@date: November 13, 2015
@brief: creates exceptions when using maze
*/
#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H

#include <stdexcept>

class MazeCreationException: public std::runtime_error{

    public:
    /*
    @pre: none
    @post: creates an exception with the message
    @return: none
    */
    MazeCreationException(const char* message);
};
#endif
