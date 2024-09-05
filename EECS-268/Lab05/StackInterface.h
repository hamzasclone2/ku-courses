/*
@file: StackInterface.h
@author: Hamza Hameed
@date: October 5, 2015
@brief: abstract class interface, extends to stack
*/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include "PreconditionViolationException.h"
template<typename T>
class StackInterface{
    public:
    /*
    @pre: none
    @post: deletes nodes in stack
    @return: none
    */
    virtual ~StackInterface(){};
    /*
    @pre: none
    @post: checks if stack is empty
    @return: true if it is, false otherwise
    */
    virtual bool isEmpty() const =0;
    /*
    @pre: valid templated value newEntry
    @post: pushes newEntry to top of stack
    @return: none
    */
    virtual void push(const T newEntry) =0;
    /*
    @pre: none
    @post: removes top value of stack, throws excpetion if
           stack is empty
    @return: none
    */
    virtual void pop() throw(PreconditionViolationException)=0;
    /*
    @pre: none
    @post: checks top value of stack, throws exception if stack is empty
    @return: value at top of list
    */
    virtual T peek()const throw(PreconditionViolationException)=0;
    /*
    @pre: none
    @post: returns m_size
    @return: m_size
    */
    virtual int size() const =0;
    /*
    @pre: none
    @post: shows list in correct order
    @return: none
    */
    virtual void print() const =0;
};
#endif
