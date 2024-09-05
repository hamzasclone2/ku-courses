#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H

#include <iostream>
class twoThreeTree{
    public:

    struct Node{ //node struct, can be either an interior or leaf node
        int key; //value of node, only used for leaves
        bool isLeaf;
        bool isTwoNode;
        int minSecond; //the min value of the second subtree
        int minThird; //the min value of the third subtree
        Node* parent;
        Node* first;
        Node* second;
        Node* third;
    };

    twoThreeTree(); //constructor
    ~twoThreeTree(); //destructor
    void insert(int val); //inserts val into tree, rearranging tree if needed
    //adds a third value into a 2-node
    void twoNodeHelper(int val, Node* node, Node* newNode);
    //finds val in tree and deletes it, rearranging tree if needed
    void erase(int val);
    void deleteMin(); //deletes the absolute min val of entire tree
    void deleteMax(); //deletes the absolute max val of entire tree
    int findMin(); //finds the min value of tree
    int findMax(); //find the max value of tree
    bool find(int val); //finds the val in the tree, true if found
    void levelOrder(); //prints out tree using list

    private:

    Node* root;

};
#endif
