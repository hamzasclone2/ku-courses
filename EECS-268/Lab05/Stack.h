
/*
@file: Stack.h
@author: Hamza Hameed
@date: October 5, 2015
@brief: Header file for stack class, uses nodes to create stack, can't
        interact with bottom of stack, only top, extends from StackInterface
*/
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"
template<typename T>
class Stack: public StackInterface<T>{
    public:
    /*
    @pre: none
    @post: checks if stack is empty
    @return: true if it is, false otherwise
    */
    virtual bool isEmpty() const;
    /*
    @pre: valid templated value newEntry
    @post: pushes newEntry to top of stack
    @return: none
    */
    virtual void push(const T newEntry);
    /*
    @pre: none
    @post: removes top value of stack, throws excpetion if
           stack is empty
    @return: none
    */
    virtual void pop() throw(PreconditionViolationException);
    /*
    @pre: none
    @post: checks top value of stack, throws exception if stack is empty
    @return: value at top of list
    */
    virtual T peek() const throw(PreconditionViolationException);
    /*
    @pre: none
    @post: returns m_size
    @return: m_size
    */
    virtual int size() const;
    /*
    @pre: none
    @post: shows list in correct order
    @return: none
    */
    virtual void print() const;
    /*
    @pre: none
    @post: deletes nodes in stack
    @return: none
    */
    ~Stack();

    private:

    int m_size=0;
    Node<T>* m_front;
};
#include "Stack.hpp"
#endif
