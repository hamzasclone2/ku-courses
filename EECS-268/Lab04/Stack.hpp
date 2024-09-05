/*
@file: Stack.hpp
@author: Hamza Hameed
@date: October 5, 2015
@brief: hpp file for stack class, handles logic for all methods
*/
#include <iostream>
template<typename T>
bool Stack<T>::isEmpty() const{
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}
template<typename T>
void Stack<T>::push(const T newEntry){
    if(isEmpty()){
        m_front=new Node<T>;
        m_front->setValue(newEntry);
        m_size++;
    }
    else{
        Node<T>* temp=m_front;
        m_front=new Node<T>;
        m_front->setValue(newEntry);
        m_front->setNext(temp);
        m_size++;
    }
}
template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException){
    if(isEmpty()){
        throw (PreconditionViolationException("Pop attempted on an empty stack"));
    }
    else{
        m_front->getValue();
        m_front=m_front->getNext();
        m_size--;
    }
}
template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException){
    if(isEmpty()){
        throw (PreconditionViolationException("Peek attempted on an empty stack"));
    }
    else{
        return m_front->getValue();
    }
}
template<typename T>
int Stack<T>::size() const{
    return m_size;
}
template<typename T>
void Stack<T>::print() const{
    if(!isEmpty()){
        Node<T>* temp=m_front;
        int i=0;
        while(i<m_size){
            std::cout << temp->getValue();
            std::cout << " ";
            temp=temp->getNext();
            i++;
        }
    }
    else if(isEmpty()){
        std::cout << "";
    }
}
template<typename T>
Stack<T>::~Stack(){
  while(!isEmpty()){
    pop();
  }
}
