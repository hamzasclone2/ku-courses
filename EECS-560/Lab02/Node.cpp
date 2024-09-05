#include "Node.h"

//constructor
Node::Node(){
    value = 0;
    next = nullptr;
}

//sets value inside node
void Node::setVal(int val){
    value = val;
}

//gets value of node
int Node::getVal(){
    return(value);
}

//sets next pointer
void Node::setNext(Node* node){
    next = node;
}

//gets the node that this node is looking at
Node* Node::getNext(){
    return next;
}
