/*
@file: BinarySearchTree.hpp
@author: Hamza Hameed
@date: November 4, 2015
@brief: creates the tree, inherits from an interface
*/
#include "BinarySearchTree.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree(){
    m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){
    if(other.isEmpty()){
        m_root = nullptr;
    }
    else{
        m_root = new Node<T>(*(other.m_root));
    }
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    if(!isEmpty()){
        deleteTree(m_root);
    }
}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone(){
    BinarySearchTree<T>* copy = new BinarySearchTree<T>(*(this));
    return copy;
}

template <typename T>
bool BinarySearchTree<T>:: isEmpty() const{
    if(m_root == nullptr){
        return true;
    }
    return false;
}

template <typename T>
bool BinarySearchTree<T>::add(T value){
    if(!isEmpty()){
        add(value, m_root);
        return true;
    }
    else{
        m_root = new Node<T>;
        m_root -> setValue(value);
        m_root -> setLeft(nullptr);
        m_root -> setRight(nullptr);
        return true;
    }
    return false;
}

template <typename T>
bool BinarySearchTree<T>::search(T value) const{
    return search(value, m_root);
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order) const{
    printTree(m_root, order);
}

template <typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order) const{
    std::vector<T> vec;
    treeToVector(m_root, order, vec);
    return vec;
}
//private methods below
template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subTree){
    if(value < subTree -> getValue()){
        if(subTree -> getLeft() != nullptr){
            add(value, subTree -> getLeft());
        }
        else{
            Node<T>* node = new Node<T>;
            node -> setLeft(nullptr);
            node -> setRight(nullptr);
            node -> setValue(value);
            subTree -> setLeft(node);
        }
        return true;
    }
    else if(value > subTree -> getValue()){
        if(subTree -> getRight() != nullptr){
            add(value, subTree -> getRight());
        }
        else{
            Node<T>* node = new Node<T>;
            node -> setLeft(nullptr);
            node -> setRight(nullptr);
            node -> setValue(value);
            subTree -> setRight(node);
        }
        return true;
    }
    return false;
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree){
    if(subTree -> getLeft() != nullptr){
        deleteTree(subTree -> getLeft());
    }
    if(subTree -> getRight() != nullptr){
        deleteTree(subTree -> getRight());
    }
    if(subTree != nullptr){
        delete(subTree);
        subTree = nullptr;
    }
}

template <typename T>
bool BinarySearchTree<T>::search(T value, Node<T>* subTree) const{
    Node<T>* searchPtr = m_root;
    while(searchPtr) {
        if(searchPtr -> getValue() == value){
            return true;
        }
        else if(searchPtr -> getValue() > value){
            searchPtr = searchPtr -> getLeft();
        }
        else{
            searchPtr = searchPtr -> getRight();
        }
    }
    return false;
}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subTree, Order order) const{
    std::vector<T> vec = treeToVector(order);
    for(std::size_t i = 0; i < vec.size(); i++ ){
        std::cout << vec[i] << " ";
    }
}

template <typename T>
void BinarySearchTree<T>::treeToVector(Node<T>* subTree, Order order, std::vector<T>& vec) const{
    if(order == PRE_ORDER){
        if(subTree != nullptr){
            vec.push_back(subTree -> getValue());
            treeToVector(subTree -> getLeft(), PRE_ORDER, vec);
            treeToVector(subTree -> getRight(), PRE_ORDER, vec);
        }
    }
    else if(order == IN_ORDER){
        if(subTree != nullptr){
            treeToVector(subTree -> getLeft(), IN_ORDER, vec);
            vec.push_back(subTree -> getValue());
            treeToVector(subTree -> getRight(), IN_ORDER, vec);
        }
    }
    else if(order == POST_ORDER){
        if(subTree != nullptr){
            treeToVector(subTree -> getLeft(), POST_ORDER, vec);
            treeToVector(subTree -> getRight(), POST_ORDER, vec);
            vec.push_back(subTree -> getValue());
        }
    }
}
