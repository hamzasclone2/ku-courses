/*
@author: Hamza Hameed
@file: Node.h
@date: September 21, 2015
@brief: This header files initialzes all the variables to be used in Node.cpp
*/
#ifndef NODE_H
#define NODE_H
class Node{
    public:
    /*
    @pre: none
    @post: an instance of node is constructed
    @return: none
    */
    Node();

    /*
    @pre: valid int
    @post: m_value=value
    @return: none
    */
    void setValue(int val);

    /*
    @pre: none
    @post: returns m_value
    @return: m_value
    */
    int getValue() const;

    /*
    @pre: none
    @post: m_next=prev
    @return: none
    */
    void setNext(Node* prev);

    /*
    @pre: none
    @post: returns m_next
    @return: m_next
    */
    Node* getNext() const;

    private:
    int m_value;
    Node* m_next;
};
#endif
