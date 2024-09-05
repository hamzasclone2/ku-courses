/*
@file: BinarySearchTree.h
@author: Hamza Hameed
@date: November 4, 2015
@brief: creates the tree, inherits from an interface
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include "Node.h"
#include "BSTI.h"

template <typename T>
class BinarySearchTree: public BSTI<T>{

    public:

    /*
    @pre: none
    @post: sets m_root to nullptr
    @return: none
    */
    BinarySearchTree();

    /*
    @pre: valid original BST
    @post: creates deep copy of other BST
    @return: none
    */
    BinarySearchTree(const BinarySearchTree<T>& other);

    /*
    @pre: none
    @post: destructs BST
    @return: none
    */
    ~BinarySearchTree();

    /*
    @pre: none
    @post: creates deep copy of BST
    @return: templated BST pointer
    */
    BSTI<T>* clone();

    /*
    @pre: none
    @post: checks if tree is empty
    @return: true if it is, false otherwise
    */
    bool isEmpty() const;

    /*
    @pre: valid value
    @post: adds value to tree
    @return: true if successful, false otherwise
    */
    bool add(T value);

    /*
    @pre: valid value
    @post: searches for value in tree
    @return: true if it is, false otherwise
    */
    bool search(T value) const;

    /*
    @pre: valid order
    @post: prints tree in specified order
    @return: none
    */
    void printTree(Order order) const;

    /*
    @pre: valid order
    @post: goes through tree in specified order
    @return: vector with contents in specified order
    */
    std::vector<T> treeToVector(Order order) const;

    private:

    Node<T>* m_root;

    /*
    @pre: valid value and subtree
    @post: adds value to correct subtree
    @return: true if successful, false otherwise
    */
    bool add(T value, Node<T>* subtree);

    /*
    @pre: valid subtree
    @post: deletes subtree
    @return: none
    */
    void deleteTree(Node<T>* subTree);

    /*
    @pre: valid valude and subtree
    @post: searches for value in the subtree
    @return: true if it is, false otherwise
    */
    bool search(T value, Node<T>* subtree) const;

    /*
    @pre: valid subtree and order
    @post: prints tree in specified order
    @return: none
    */
    void printTree(Node<T>* subtree, Order order) const;

    /*
    @pre: valid subtree, order, and vector
    @post: loads vec in the specified order
    @return: none
    */
    void treeToVector(Node<T>* subtree, Order order, std::vector<T>& vec) const;

};
#include "BinarySearchTree.hpp"
#endif
