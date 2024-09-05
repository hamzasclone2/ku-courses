/*
@author: Hamza Hameed
@file: LinkedList.h
@date: September 21, 2015
@brief: This header files initializes all the variables that will
        be used in the cpp file
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include  "Node.h"
class LinkedList{
    public:
    /*
    @pre: none
    @post:  a LinkedList instance is created
    @return: none
    */
    LinkedList();

    /*
    @pre: none
    @post: nodes are removed
    @return: none
    */
    ~LinkedList();

    /*
    @pre: none
    @post: checks if list is empty or not
    @return: true if it is, else false
    */
    bool isEmpty() const;

    /*
    @pre: none
    @post: checks size for list
    @return: an integer that is the size of the list
    */
    int size() const;

    /*
    @pre: value is a valid int
    @post: searches for user defined value in list
    @return: true if it is, else false
    */
    bool search(int value) const;

    /*
    @pre: none
    @post: list is printed from front to back
    @return: none
    */
    void printList() const;

    /*
    @pre: a valid integer
    @post: int is added to back of list
    @return: none
    */
    void addBack(int value);

    /*
    @pre: valid int
    @post: int is added to front of list
    @return: none
    */
    void addFront(int value);

    /*
    @pre: none
    @post: last int in list is removed
    @return: true if there is one to be removed, else false
    */
    bool removeBack();

    /*
    @pre: none
    @post: first int in list is removed
    @return: true if there is an int to be removed, else false
    */
    bool removeFront();

    private:
    Node* m_front;
    int m_size;
};
#endif
