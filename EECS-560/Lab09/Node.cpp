#include "Node.h"

//constructor
Node::Node(){
    value = 0;
    left = nullptr;
    right = nullptr;
}

//sets value inside node
void Node::setVal(int val){
    value = val;
}

//gets value of node
int Node::getVal(){
    return value;
}

//sets the pointer on the left
void Node::setLeft(Node* node){
    left = node;
}

//returns the node on the left
Node* Node::getLeft(){
    return left;
}

//sets the right pointer to a node
void Node::setRight(Node* node){
    right = node;
}

//returns the node on the right
Node* Node::getRight(){
    return right;
}
