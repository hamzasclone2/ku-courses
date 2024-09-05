/*
* @name: Node.h
* @author: Hamza Hameed
* @date: September 29, 2015
* @brief: The header file for node
*/


#include <iostream>
#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
  public:
  /*
  @pre: none
  @post: a templated node instance is created
  @return: none
  */
  Node();
  /*
  @pre: valid templated node pointer
  @post: sets m_previous to prev
  @return: none
  */
  void setPrevious(Node<T>* prev);
  /*
  @pre: none
  @post: gets value for m_previous
  @return: m_previous
  */
  Node<T>* getPrevious() const;
  /*
  @pre: valid templated node pointer
  @post: sets m_next to prev
  @return: none
  */
  void setNext(Node<T>* prev);
  /*
  @pre: none
  @post: returns value for m_next
  @return: m_next
  */
  Node<T>* getNext() const;
  /*
  @pre: valid template value
  @post: sets m_value to value
  @return: none
  */
  void setValue(T value);
  /*
  @pre: none
  @post: returns value for m_value
  @return: m_value
  */
  T getValue() const;
  private:
  T m_value;
  Node<T>* m_previous;
  Node<T>* m_next;

};

#include "Node.hpp"
#endif
