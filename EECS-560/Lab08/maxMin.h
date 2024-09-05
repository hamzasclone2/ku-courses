#ifndef MAXMIN_H
#define MAXMIN_H

class maxMin{

    public:

    maxMin(); //constructor
    ~maxMin(); //destructor
    void buildHeap(); //takes in data file to populate array
    void insert(int val); //inserts value at last+1
    void deleteMin(); //deletes min value, replaces with last
    int findMin(); //returns one of the children of the root
    int findMax(); //returns the root
    void deleteMax(); //deletes max value, replaces with last
    void levelOrder(); //prints out array in order

    private:

    int* heap;
    int size;
    int lastIdx;
};
#endif
