/*
@file: Node.hpp
@author: Hamza Hameed
@date: October 5, 2015
@brief: logic for node class, resused from last lab
*/
#include "Node.h"
template<typename T>
Node<T>::Node(){
    m_value=T();
    m_next=nullptr;
}
template<typename T>
void Node<T>::setNext(Node<T>* prev){
    m_next=prev;
}
template<typename T>
Node<T>* Node<T>::getNext() const{
    return m_next;
}
template<typename T>
void Node<T>::setValue(T value){
    m_value=value;
}
template<typename T>
T Node<T>::getValue() const{
return m_value;
}
