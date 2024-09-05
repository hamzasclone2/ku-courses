#include <iostream>
#include <fstream>
#include "Hash.h"
#include "List.h"
#include "Node.h"

//constructor
Hash::Hash(){
    
}

//destructor
Hash::~Hash(){
    for(int i = 0; i < tableSize; i++){
        hashTable[i].~List();
    }
}

void Hash::setTableSize(int val){
    tableSize = val;
    hashTable = new List[tableSize];
}

//hashes the key, then inserts value at the index generated
void Hash::insert(int val){
    int index = hashFunc(val);
    hashTable[index].insertFront(val);
}

//finds the value in the table by hashing, then deletes
void Hash::erase(int val){
    int index = hashFunc(val);
    hashTable[index].erase(val);

}

//prints out full hash table
void Hash::print(){
    std::cout << "\n";
    for(int i = 0; i < tableSize; i++){
        if(!hashTable[i].isEmpty()){
            std::cout << i << ": ";
            hashTable[i].print();
            std::cout << "\n";
        }
    }
}

//hashes the given key
int Hash::hashFunc(int val){
    return val % tableSize;
}

//returns false if value is not found, else true
bool Hash::find(int val){
    int index = hashFunc(val);
    if(hashTable[index].find(val) == nullptr){
        return false;
    }else{
        return true;
    }
}
