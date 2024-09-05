/*
@author: Hamza Hameed
@file: Node.cpp
@date: September 21, 2015
@brief: This class contains the Node constructor and the get and set methods
*/
#include "Node.h"

Node::Node(){
    m_value=0;
    m_next=nullptr;
}
void Node::setValue(int val){
    m_value=val;
}
int Node::getValue() const{
    return(m_value);
}
void Node::setNext(Node* prev){
    m_next=prev;
}
Node* Node::getNext() const{
    return(m_next);
}
