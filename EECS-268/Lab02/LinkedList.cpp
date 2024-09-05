/*
@author: Hamza Hameed
@file: LinkedList.cpp
@date: September 21, 2015
@brief: This cpp files handles almost all of the logic of the List.
        It is what actually carries out all of the functions that the
        user chooses.
*/
#include "LinkedList.h"
#include "Node.h"
#include <iostream>

LinkedList::LinkedList(){
    m_front=nullptr;
    m_size=0;
}
LinkedList::~LinkedList(){
    while(!isEmpty()){
        removeFront();
    }
}
bool LinkedList::isEmpty() const{
    if(m_front==nullptr){
        return(true);
    }
    else{
        return(false);
    }
}
int LinkedList::size()const{
    return(m_size);
}
bool LinkedList::search(int value) const{
    if(isEmpty()){
        return(false);
    }
    else{
        Node* searchptr=m_front;
        for(int i=0; i<m_size; i++){
            if(searchptr -> getValue()==value){
                searchptr=nullptr;
                return(true);
            }
            searchptr=searchptr->getNext();
        }
        searchptr=nullptr;
    }
    return(false);
}
void LinkedList::printList() const{
    Node* printptr=new Node();
    if(!isEmpty()){
        std::cout << m_front -> getValue() << " ";
        printptr=m_front;
        while(printptr->getNext()!=nullptr){
            printptr=printptr->getNext();
            std::cout << printptr->getValue() << " ";
        }
    }
    else{
        std::cout << "";
    }
    printptr=printptr->getNext();
}
void LinkedList::addBack(int value){
    Node* temp=nullptr;
    if(isEmpty()){
        m_front=new Node();
        m_front -> setValue(value);
        m_size++;
    }
    else{
        temp=m_front;
        while(temp -> getNext()!=nullptr){
            temp=temp -> getNext();
        }
        temp->setNext(new Node());
        temp->getNext()->setValue(value);
        m_size++;
    }
}
void LinkedList::addFront(int value){
    if(isEmpty()){
        m_front=new Node();
        m_front->setValue(value);
        m_size++;
    }
    else{
        Node* temp=m_front;
        m_front=new Node();
        m_front -> setValue(value);
        m_front -> setNext(temp);
        m_size++;
    }
}
bool LinkedList::removeBack(){

    if(!isEmpty()){
        Node* temp=m_front;
        for(int i=0; i<m_size-2; i++){
            temp=temp -> getNext();
        }
        temp -> setNext(nullptr);
        m_size--;
        return(true);
    }
    else{
        return(false);
    }
}
bool LinkedList::removeFront(){

    if(!isEmpty()){
        Node* temp=m_front;
        m_front=m_front -> getNext();
        m_size--;
        delete temp;
        temp=nullptr;
        return(true);
    }
    else{
        return(false);
    }
}
