/*
* @name: DoubleLinkedList.h
* @author: Hamza Hameed
* @date: September 29, 2015
* @brief: The header file for the double linked list
*/


#include <iostream>
#include "Node.h"
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
template <typename T>
class DoubleLinkedList
{
  public:
  /*
  @pre: none
  @post: a templated double linked list instance is created
  @return: none
  */
  DoubleLinkedList();
  /*
  @pre: none
  @post: all new nodes are successfully deleted
  @return: none
  */
  ~DoubleLinkedList();
  /*
  @pre: none
  @post: checks if list is empty
  @return: true if it is, false otherwise
  */
  bool isEmpty() const;
  /*
  @pre: none
  @post: returns m_size
  @return: m_size
  */
  int size() const;
  /*
  @pre: valid templated value
  @post: pushes a value to front of list
  @return: none
  */
  void pushFront(T value);
  /*
  @pre: valid templated value
  @post: pushes value to the back of the list
  @return: none
  */
  void pushBack(T value);
  /*
  @pre: none
  @post: removes value at the back of the list
  @return: false if it is empty, true otherwise
  */
  bool removeBack();
  /*
  @pre: none
  @post: removes value at front of list
  @return: false if list is empty, true otherwise
  */
  bool removeFront();
  /*
  @pre: valid templated value
  @post: removes value chosen by user from list
  @return: true if value is deleted, false otherwise
  */
  bool remove(T value);
  /*
  @pre: valid listValue and newValue
  @post: inserts newValue in front of the listValue
  @return: none
  */
  void insertAhead(T listValue, T newValue) throw (std::runtime_error);
  /*
  @pre: valid listValue and newValue
  @post: insets newValue behind listValue
  @return: none
  */
  void insertBehind(T listValue, T newValue) throw (std::runtime_error);
  /*
  @pre: valid value
  @post: finds value in list
  @return: value if found
  */
  Node<T>* find(T value) const;
  /*
  @pre: none
  @post: prints out contents of list
  @return: none
  */
  void printList() const;
  private:
  Node<T>* m_front;
  Node<T>* m_back;
  int m_size;

};

#include "DoubleLinkedList.hpp"
#endif
