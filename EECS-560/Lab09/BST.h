#ifndef BST_H
#define BST_H
#include "Node.h"
#include <string>

class BST{

    public:

    BST(); //constructor

    ~BST(); //destructor

    bool isEmpty(); //true if root ==  nullptr, false otherwise

    void insert(int val); //inserts a value by checking subtrees

    void recurse(int val, Node* node); //recurses through tree to get to bottom

    void erase(int val); //erases indicated value

    void deleteMin(); //deletes the minimum value in the tree

    void deleteMax(); //deletes the maximum value in the tree

    int findMin(); //finds the minimum value in the tree

    int findMax(); //finds the maximum value in the tree

    void print(std::string order); //calls various order functions in order to print

    void preorder(Node* subTree); //uses preorder to print

    void inorder(Node* subTree); //uses inorder to print

    void postorder(Node* subTree); //uses postorder to print

    private:

    Node* root;
};
#endif
