/*
@file: BSTI.H
@author: Hamza Hameed
@date: November 4, 2015
@brief: interface class for a BST
*/
#ifndef BSTI_H
#define BSTI_H
#include <vector>

enum Order{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

template <typename T>
class BSTI{

    public:

    /*
    @pre: a BSTI exists
    @post: deletes entire tree
    @return: none
    */
    virtual ~BSTI(){};

    /*
    @pre: none
    @post: creates a deep copy
    @return: pointer to deep copy
    */
    virtual BSTI<T>* clone() =0;

    /*
    @pre: none
    @post: checks if BST is empty
    @return: true if it is, false otherwise
    */
    virtual bool isEmpty() const =0;

    /*
    @pre: valid value
    @post: adds value to tree
    @return: true if successful, false otherwise
    */
    virtual bool add(T value) =0;

    /*
    @pre: valid value
    @post: searches for value in BST
    @return: true if it is, false otherwise
    */
    virtual bool search(T value) const =0;

    /*
    @pre: valid order
    @post: prints out tree in specified order
    @return: none
    */
    virtual void printTree(Order order) const =0;

    /*
    @pre: valid order
    @post: goes through tree in specified order
    @return: vector with contents in specified order
    */
    virtual std::vector<T> treeToVector(Order order) const =0;
};
#endif
