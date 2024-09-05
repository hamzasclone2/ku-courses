#include "BST.h"
#include <iostream>

//constructor
BST::BST(){
    root = nullptr;
}

//destructor
BST::~BST(){

}

//true if root ==  nullptr, false otherwise
bool BST::isEmpty(){
    if(root == nullptr){
        return true;
    }else{
        return false;
    }
}

//inserts a value by checking subtrees
void BST::insert(int val){
    Node* newNode = new Node();
    newNode -> setVal(val);
    newNode -> setLeft(nullptr);
    newNode -> setRight(nullptr);
    if(isEmpty()){
        root = newNode;
    }else{
        recurse(val, root);
    }
}

//recurses through tree to get to bottom
void BST::recurse(int val, Node* subTree){
    if(val < subTree -> getVal()){
        if(subTree -> getLeft() != nullptr){
            recurse(val, subTree -> getLeft());
        }else{
            Node* newNode = new Node();
            newNode -> setVal(val);
            newNode -> setLeft(nullptr);
            newNode -> setRight(nullptr);
            subTree -> setLeft(newNode);
        }
    }else if(val > subTree -> getVal()){
        if(subTree -> getRight() != nullptr){
            recurse(val, subTree -> getRight());
        }else{
            Node* newNode = new Node();
            newNode -> setVal(val);
            newNode -> setLeft(nullptr);
            newNode -> setRight(nullptr);
            subTree -> setRight(newNode);
        }
    }
}

void BST::erase(int val){

}
//deletes the minimum value in the tree
void BST::deleteMin(){

}

//deletes the maximum value in the tree
void BST::deleteMax(){

}

//finds the minimum value in the tree
int BST::findMin(){
    Node* temp = root;
    while(temp -> getLeft() != nullptr){
        temp = temp -> getLeft();
    }
    return(temp -> getVal());
}

//finds the maximum value in the tree
int BST::findMax(){
    Node* temp = root;
    while(temp -> getRight() != nullptr){
        temp = temp -> getRight();
    }
    return(temp -> getVal());
}

//calls various order functions in order to print
void BST::print(std::string order){
    if(order == "preorder"){
        preorder(root);
    }else if(order == "inorder"){
        inorder(root);
    }else if(order == "postorder"){
        postorder(root);
    }
}

//uses preorder to print
void BST::preorder(Node* subTree){
    if(subTree != nullptr){
        std::cout << subTree -> getVal() << " ";
        preorder(subTree -> getLeft());
        preorder(subTree -> getRight());
    }
}

//uses inorder to print
void BST::inorder(Node* subTree){
    if(subTree != nullptr){
        inorder(subTree -> getLeft());
        std::cout << subTree -> getVal() << " ";
        inorder(subTree -> getRight());
    }
}

//uses postorder to print
void BST::postorder(Node* subTree){
    if(subTree != nullptr){
        postorder(subTree -> getLeft());
        postorder(subTree -> getRight());
        std::cout << subTree -> getVal() << " ";
    }
}
