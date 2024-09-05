/*
@file: Node.h
@author: Hamza Hameed
@date: November 4, 2015
@brief: the nodes that make up the BST
*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{

    private:

    Node<T>* m_left;
    Node<T>* m_right;
    T m_value;

    public:

    /*
    @pre: none
    @post: sets m_left and m_right to nullptr
    @return: none
    */
    Node();

    /*
    @pre: valid original node
    @post: copies other node
    @return: none
    */
    Node(const Node<T>& other);

    /*
    @pre: none
    @post: gets m_value
    @return: m_value
    */
    T getValue() const;

    /*
    @pre: none
    @post: gets m_left
    @return: m_left
    */
    Node<T>* getLeft() const;

    /*
    @pre: none
    @post: gets m_right
    @return: m_right
    */
    Node<T>* getRight() const;

    /*
    @pre: valid value
    @post: sets m_value to value
    @return: none
    */
    void setValue(T value);

    /*
    @pre: valid pointer left
    @post: sets m_left to left
    @return: none
    */
    void setLeft(Node<T>* left);

    /*
    @pre: valid pointer right
    @post: sets m_right to right
    @return: none
    */
    void setRight(Node<T>* right);
};
#include "Node.hpp"
#endif
