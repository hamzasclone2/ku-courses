/*
@file: Node.h
@author: Hamza Hameed
@date: October 5, 2015
@brief: header file for node class, resused from previous lab
        minus setPrevious and getPrevious
*/
#ifndef NODE_H
#define NODE_H
template<typename T>
class Node{

    public:
    /*
    @pre: none
    @post: creates instance of node
    @return: none
    */
    Node();
    /*
    @pre: valid templated node pointer prev
    @post: sets m_next to prev
    @return: none
    */
    void setNext(Node<T>* prev);
    /*
    @pre: none
    @post: gets m_value
    @return: m_next
    */
    Node<T>* getNext() const;
    /*
    @pre: valid templated type value
    @post: sets m_value to value
    @return: none
    */
    void setValue(T value);
    /*
    @pre: none
    @post: gets m_value
    @return: m_value
    */
    T getValue() const;

    private:

    T m_value;
    Node<T>* m_next;
};
#include "Node.hpp"
#endif
