#ifndef MINMAX_H
#define MINMAX_H

class minMax{

    public:

    minMax(); //constructor
    ~minMax(); //destructor
    void buildHeap(); //takes in values from data file to populate array
    void insert(int val); //inserts value at last+1
    void deleteMin(); //deletes root, replaces with last
    int findMin(); //returns root
    int findMax(); //returns one of the roots children
    void deleteMax(); //deletes max, replaces with last
    void levelOrder(); //prints out array in order

    private:

    int* heap;
    int size;
    int lastIdx;
};
#endif
