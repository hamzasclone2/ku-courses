/*
@file: PreconditionViolationException.h
@author: Hamza Hameed
@date: October 5, 2015
@brief: Header file for pveh, extends from runtime_error
*/
#ifndef P_V_E_H
#define P_V_E_H
#include <stdexcept>

class PreconditionViolationException : public std::runtime_error{
    public:
    /*
    @pre: valid error message
    @post: passes message into std::runtime_error
    @return: none
    */
    PreconditionViolationException(const char* message);
};
#endif
