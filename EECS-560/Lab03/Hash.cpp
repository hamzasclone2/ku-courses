#include <iostream>
#include <fstream>
#include "Hash.h"

//constructor
Hash::Hash(){
    tableSize = 53;
    k = 10;
    p = 13;
    qp_HashTable = new int[tableSize];
    dh_HashTable = new int[tableSize];
    for(int i = 0; i < tableSize; i++){
        qp_HashTable[i] = -1;
        dh_HashTable[i] = -1;
    }
    qp_insertedValues = 0;
    dh_insertedValues = 0;
}

//destructor
Hash::~Hash(){
    delete qp_HashTable;
    delete dh_HashTable;
}
//tries to insert val into quadratic probing array
//insertion can fail
bool Hash::qp_insert(int val){
    int index = val % tableSize;
    if(qp_HashTable[index] == -1){
        qp_HashTable[index] = val;
        qp_insertedValues++;
        return true;
    }else{
        index = quadraticProbing(val, index);
        if(index != -1){
            qp_HashTable[index] = val;
            qp_insertedValues++;
            return true;
        }else{
            return false;
        }
    }
}

//tries to insert val into double hashing array
//insertion can fail
bool Hash::dh_insert(int val){
    int index = val % tableSize;
    if(dh_HashTable[index] == -1){
        dh_HashTable[index] = val;
        dh_insertedValues++;
        return true;
    }else{
        index = doubleHashing(val, index);
        if(index != -1){
            dh_HashTable[index] = val;
            dh_insertedValues++;
            return true;
        }else{
            return false;
        }
    }
}

//calculates load factor for quadratic probing array
double Hash::qp_loadFactor(){
    float a = (float)qp_insertedValues;
    float b = (float)tableSize;
    return a / b;
}

//calculates load factor for double hashing array
double Hash::dh_loadFactor(){
    float a = (float)dh_insertedValues;
    float b = (float)tableSize;
    return a / b;
}

//erases the val from the qp array if it exists
bool Hash::qp_erase(int val){
    if(qp_find(val) != -1){
        qp_HashTable[qp_find(val)] = -1;
        return true;
    }else{
        return false;
    }
}

//erases the val from the dh array if it exists
bool Hash::dh_erase(int val){
    if(dh_find(val) != -1){
        dh_HashTable[dh_find(val)] = -1;
        return true;
    }else{
        return false;
    }
}

//prints both hash tables, only prints out indeces with actual values
void Hash::print(){
    std::cout << "\nHash table with quadratic probing:\n";
    for(int i = 0; i < tableSize; i++){
        if(qp_HashTable[i] != -1){
            std::cout << i << ": " << qp_HashTable[i] << "\n";
        }
    }
    std::cout << "\nHash table with double hashing:\n";
    for(int i = 0; i < tableSize; i++){
        if(dh_HashTable[i] != -1){
            std::cout << i << ": " << dh_HashTable[i] << "\n";
        }
    }
}

//tries to find value in qp array
//returns -1 if not found, else returns the index
int Hash::qp_find(int val){
    for(int i = 0; i < tableSize; i++){
        if(qp_HashTable[i] == val){
            return i;
        }
    }
    return -1;
}

//tries to find value in dh array
//returns -1 if not found, else returns the index
int Hash::dh_find(int val){
    for(int i = 0; i < tableSize; i++){
        if(dh_HashTable[i] == val){
            return i;
        }
    }
    return -1;
}

//uses i^2 to find an index if the place is already taken during insertion
int Hash::quadraticProbing(int val, int index){
    int h_x = val % tableSize;
    int f_i = index * index;
    int hi_x = 0;
    for(int i = 0; i < k; i++){
        hi_x = (h_x + f_i) % tableSize;
        if(qp_HashTable[hi_x] == -1){
            return hi_x;
        }else{
            f_i += f_i;
        }
    }
    return -1;
}

//uses p-xmodp to find an index if the place is already taken during insertion
int Hash::doubleHashing(int val, int index){
    int h_x = val % tableSize;
    int hplus_x = p - val % p;
    int f_i = index * hplus_x;
    int hi_x = 0;
    for(int i = 0; i < k; i++){
        hi_x = (h_x + f_i) % tableSize;
        if(dh_HashTable[hi_x] == -1){
            return hi_x;
        }else{
            f_i += f_i;
        }
    }
    return -1;
}
