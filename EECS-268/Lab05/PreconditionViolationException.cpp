/*
@file: PreconditionViolationException.cpp
@author: Hamza Hameed
@date: October 5, 2015
@brief: hpp file for pveh, only mehtod is empty
*/
#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(
const char* message) : std::runtime_error(message){

}
