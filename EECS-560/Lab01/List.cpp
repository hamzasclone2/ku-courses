#include "List.h"
#include "Node.h"

#include <iostream>

//constructor
List::List(){
    head = nullptr;
}

//destructor
List::~List(){
    Node* temp = head;
    while(temp != nullptr){
        Node* next = temp -> getNext();
        delete temp;
        temp = next;
    }
}

//takes in value to be inserted into the list
//calls recurseInsert to navigate to end of list recursively
void List::insert(int val){
    Node* temp = nullptr;

    Node* newNode = new Node();
    newNode -> setVal(val);
    newNode -> setNext(nullptr);
    if(isEmpty()){
        head = newNode;
    }else{
        temp = recurseInsert(head);
        temp -> setNext(newNode);
    }
}

//navigates to end of list using recursion
Node* List::recurseInsert(Node* node){
    Node* temp = node;
    if(temp -> getNext() == nullptr){
        return temp;
    }else{
        temp = temp -> getNext();
        temp = recurseInsert(temp);
        return temp;
    }
}

//checks if list has any nodes in it
//returns true if it is empty, otherwise false
bool List::isEmpty(){
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}

//erases the node that holds the value from the list
//calls recurseErase to recursively navigate to node before the
//to be deleted node
void List::erase(int val){
	Node* temp = head;
	Node* next = nullptr;
	if(head -> getVal() == val){
		head = head -> getNext();
		delete temp;
	}else{
		temp = recurseErase(head, val);
		if(temp -> getNext() == nullptr && temp -> getVal() == val){
			delete temp;
		}else{
			next = temp -> getNext();
			temp -> setNext(next -> getNext());
			delete next;
		}
	}
}

//recursively navigates to node before the val
Node* List::recurseErase(Node* node, int val){
	while(node != nullptr){
		if(node -> getNext() == nullptr){
			return nullptr;
		}else if(node -> getNext() -> getVal() == val){
			return node;
		}else{
			node = recurseErase(node -> getNext(), val);
			return node;
		}
	}
}

//prints the list iteratively
void List::print(){
    std::cout << "\nList: ";
    Node* temp = head;
    while(temp != nullptr){
        std::cout << temp -> getVal();
        std::cout << " ";
        temp = temp -> getNext();
    }
}

//checks if the value exists in the list
//returns nullptr if it is not, otherwise returns the node
Node* List::find(int val){
    Node* temp = head;
    if (isEmpty()){
        return nullptr;
    }else{
        while(temp != nullptr){
            if(temp -> getVal() == val){
                return temp;
            }
            temp = temp -> getNext();
        }
        return nullptr;
    }
}
