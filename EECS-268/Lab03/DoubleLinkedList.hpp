/*
* @name: DoubleLinkedList.hpp
* @author: Hamza Hameed
* @date: September 29, 2015
* @brief: Handles all the logic for the linked list
*/

#include <iostream>
#include "DoubleLinkedList.h"
//not sure if below is NEEDED but it wasn't working without it
#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
  m_size = 0;
  m_front = nullptr;
  m_back = nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
  while(!isEmpty())
  {
    removeBack();
  }
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
  if(m_size == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
  return m_size;
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
  if(isEmpty())
  {
    m_front = new Node<T>;
    m_front -> setValue(value);
    m_back = m_front;
    m_size++;
  }
  else
  {
    Node<T>* temp = m_front;
    m_front = new Node<T>;
    m_front -> setValue(value);
    m_front -> setNext(temp);
    temp -> setPrevious(m_front);
    m_size++;
  }
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
  if(isEmpty())
  {
    m_front = new Node<T>;
    m_front -> setValue(value);
    m_back = m_front;
    m_size++;
  }
  else
  {
    Node<T>* temp = m_back;
    m_back = new Node<T>;
    m_back -> setValue(value);
    temp -> setNext(m_back);
    m_back -> setPrevious(temp);
    m_size++;
  }
}

template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
  if(isEmpty())
  {
    return false;
  }
  else if(m_size > 1)
  {
    Node<T>* temp = m_back;
    m_back = m_back -> getPrevious();
    delete temp;
    m_size--;
    return true;
  }
  else
  {
    delete m_back;
    m_size--;
    return true;
  }
}

template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
  if(isEmpty())
  {
    return false;
  }
  else if(m_size == 1)
  {
    delete m_front;
    m_size--;
    return true;
  }
  else
  {
    Node<T>* temp=m_front;
    m_front=m_front -> getNext();
    m_size--;
    delete temp;
    return true;
  }
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
  if(!isEmpty())
  {
    Node<T>* temp=find(value);
    if(temp == nullptr)
    {
      return false;
    }
    if(temp -> getPrevious() == nullptr)
    {
      if(temp -> getNext() != nullptr)
      {
        m_front = temp -> getNext();
      }
      else
      {
        m_front -> setNext(nullptr);
      }
      m_front -> setPrevious(nullptr);
      delete temp;
      m_size--;
      return true;
    }
    else if(temp -> getNext() == nullptr)
    {
      if(temp -> getPrevious() != nullptr)
      {
        m_back = temp -> getPrevious();
      }
      else
      {
        m_back -> setPrevious(nullptr);
      }
      m_back ->setNext(nullptr);
      delete temp;
      m_size--;
      return true;
    }
    else
    {
      temp -> getPrevious() -> setNext(temp -> getNext());
      temp -> getNext() -> setPrevious(temp -> getPrevious());
      delete temp;
      m_size--;
      return true;
    }
  }
  return false;
}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
  Node<T>* temp = find(listValue);
  if(temp == nullptr)
  {
    throw std::runtime_error("This is broken dude");
  }
  else
  {
    if(temp -> getNext() == nullptr)
    {
      pushBack(newValue);
    }
    else
    {
      Node<T>* newNode = new Node<T>;
      newNode -> setValue(newValue);
      newNode -> setNext(temp -> getNext());
      temp -> setNext(newNode);
      newNode -> setPrevious(temp);
      newNode -> getNext() -> setNext(newNode);
    }
  }
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
  Node<T>* temp = find(listValue);
  if(temp == nullptr)
  {
    throw std::runtime_error("Error! Everythings messed up");
  }
  else
  {
    if(temp -> getPrevious() == nullptr)
    {
      pushFront(newValue);
    }
    else
    {
      Node<T>* newNode = new Node<T>;
      newNode -> setValue(newValue);
      newNode -> setPrevious(temp -> getPrevious());
      temp -> setPrevious(newNode);
      newNode -> setNext(temp);
      newNode -> getPrevious() -> setNext(newNode);
      m_size++;
    }
  }
}
template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
  if(!isEmpty())
  {
    Node<T>* temp=m_front;
    for(int x = 0; x < m_size; x++)
    {
      if(temp -> getValue() == value)
      {
        return temp;
      }
      else
      {
        temp = temp -> getNext();
      }
    }
  }
  return nullptr;
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
  if(!isEmpty())
  {
    Node<T>* temp = m_front;
    for(int x = 0; x < m_size; x++)
    {
      std::cout << temp -> getValue() << " ";
      temp = temp -> getNext();
    }
  }
  else
  {
    std::cout << "";
  }
}
#endif
