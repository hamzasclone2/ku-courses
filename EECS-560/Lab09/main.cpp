#include "BST.h"
#include "min5heap.h"
#include "max5heap.h"
#include "timerClass.cpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main(){
    Timer t;
    int randNum;

    BST* bst;
    min5heap* minHeap;
    max5heap* maxHeap;

    double maxbuildtotal = 0;
    double maxdmintotal = 0;
    double maxdmaxtotal = 0;
    double minbuildtotal = 0;
    double mindmintotal = 0;
    double mindmaxtotal = 0;
    double bstbuildtotal = 0;

    int arraySize = 10000000;
    int m = 1000000;
    int* array = new int[arraySize];

    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            std::cout << "Working...\n";
            maxHeap = new max5heap;
            minHeap = new min5heap;
            bst = new BST();

            srand(time(NULL));

            for(int i = 0; i < arraySize; i++){
                randNum = rand() % (5*m) + 1;
                array[i] = randNum;
            }

            t.start();
            for(int i = 0; i < m; i++){
                bst -> insert(array[i]);
            }
            bstbuildtotal += t.stop();

            t.start();
            maxHeap -> buildHeap(arraySize, array);
            maxbuildtotal += t.stop();

            t.start();
            minHeap -> buildHeap(arraySize, array);
            minbuildtotal += t.stop();

            t.start();
            for(int i = 0; i < (.001*m); i++){
                maxHeap -> deleteMin();
            }
            maxdmintotal += t.stop();

            t.start();
            for(int i = 0; i < (.001*m); i++){
                minHeap -> deleteMin();
            }
            mindmintotal += t.stop();

            t.start();
            for(int i = 0; i < (.001*m); i++){
                maxHeap -> deleteMax();
            }
            maxdmaxtotal += t.stop();

            t.start();
            for(int i = 0; i < (.001*m); i++){
                minHeap -> deleteMax();
            }
            mindmaxtotal += t.stop();
        }

        std::cout << "BST build with " << m << " values: "
                  << bstbuildtotal/5.0 << "\n";

        std::cout << "Max-5-heap build with " << m << " values: "
                  << maxbuildtotal/5.0 << "\n";

        std::cout << "Max-5-heap delete min with " << .001*m << " values: "
                  << maxdmintotal/5.0 << "\n";

        std::cout << "Max-5-heap delete max with " << .001*m << " values: "
                  << maxdmaxtotal/5.0 << "\n";

        std::cout << "Min-5-heap build with " << m << " values: "
                  << minbuildtotal/5.0 << "\n";

        std::cout << "Min-5-heap delete min with " << .001*m << " values: "
                  << mindmintotal/5.0 << "\n";

        std::cout << "Min-5-heap delete max with " << .001*m << " values: "
                  << mindmaxtotal/5.0 << "\n";

        m += 1000000;
    }

    return 0;
}
