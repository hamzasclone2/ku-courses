#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

class closedHash{
    public:

    closedHash(); //constructor
    ~closedHash(); //destructor

    void setValues(int newK, int newP, int newTableSize);

    //tries to insert val into quadratic probing array
    //insertion can fail
    bool qp_insert(int val);

    //tries to insert val into double hashing array
    //insertion can fail
    bool dh_insert(int val);

    //calculates load factor for quadratic probing array
    double qp_loadFactor();

    //calculates load factor for double hashing array
    double dh_loadFactor();

    //erases the val from both the qp array if it exists
    bool qp_erase(int val);

    //erases the val from both the dh array if it exists
    bool dh_erase(int val);

    //prints both hash tables, only prints out indeces with actual values
    void print();

    //tries to find value in qp array
    //returns -1 if not found, else returns the index
    int qp_find(int val);

    //tries to find value in dh array
    //returns -1 if not found, else returns the index
    int dh_find(int val);

    //uses i^2 to find an index if the place is already taken during insertion
    int quadraticProbing(int val, int index);

    //uses p-xmodp to find an index if the place is already taken during insertion
    int doubleHashing(int val, int index);

    private:

    int* qp_HashTable; //quadratic probing hash table
    int* dh_HashTable; //double hashing hash table
    int tableSize;
    int k; //number of tries for an insertion
    int p; //value used in doubleHashing
    //counts # of values that are successfully inserted into the qp_array
    int qp_insertedValues;
    //counts # of values that are successfully inserted into the dh_array
    int dh_insertedValues;

};
#endif
