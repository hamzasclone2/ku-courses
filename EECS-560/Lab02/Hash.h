#ifndef HASH_H
#define HASH_H
#include "Node.h"
#include "List.h"

class Hash{
    public:

    //constructor
    Hash();
    //destructor
    ~Hash();

    //hashes the key, then inserts value at the index generated
    void insert(int val);

    //finds the value in the table by hashing, then deletes
    void erase(int val);

    //prints out full hash table
    void print();

    //hashes the given key
    int hashFunc(int val);

    //returns false if value is not found, else true
    bool find(int val);

    private:

    int tableSize;
    List* hashTable;
};
#endif
