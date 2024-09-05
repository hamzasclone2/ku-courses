/*
* @name: Node.hpp
* @author: Hamza Hameed
* @date: September 29, 2015
* @brief: Handles all the logic for the nodes
*/
#include <iostream>
#include "Node.h"
//not sure if below is NEEDED but it wasn't working without it
#ifndef NODE_HPP
#define NODE_HPP
 template <typename T>
 Node<T>::Node()
 {
   m_value = T();
   m_previous = nullptr;
   m_next = nullptr;
 }

 template <typename T>
 void Node<T>::setPrevious(Node<T>* prev)
 {
   m_previous = prev;
 }

 template <typename T>
 Node<T>* Node<T>::getPrevious() const
 {
   return m_previous;
 }

 template <typename T>
 void Node<T>::setNext(Node<T>* prev)
 {
   m_next = prev;
 }

 template <typename T>
 Node<T>* Node<T>::getNext() const
 {
   return m_next;
 }

 template <typename T>
 void Node<T>::setValue(T value)
 {
   m_value = value;
 }

 template <typename T>
 T Node<T>::getValue() const
 {
   return m_value;
 }
#endif
