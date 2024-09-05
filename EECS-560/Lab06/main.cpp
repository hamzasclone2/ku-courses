#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Hash.h"
#include "closedHash.h"
#include "timerClass.cpp"

void printMenu(){
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << "Please choose one of the following commands:\n"
              << "1- Test HashTables\n"
              << "2- Performance Comparison\n"
              << "3- Exit\n"
              << "> ";
}

int main(int argc, char* argv[]){
    Timer t;
    int data;
    int choice;
    int userTableSize;
    int tableSize;
    Hash* testHash = new Hash();
    closedHash* testCH = new closedHash();
    Hash* hash1 = new Hash();
    Hash* hash2 = new Hash();
    Hash* hash3 = new Hash();
    Hash* hash4 = new Hash();
    Hash* hash5 = new Hash();
    closedHash* ch1 = new closedHash();
    closedHash* ch2 = new closedHash();
    closedHash* ch3 = new closedHash();
    closedHash* ch4 = new closedHash();
    closedHash* ch5 = new closedHash();
    while(true){
        printMenu();
        std::cin >> choice;
        if(choice == 1){
            std::cout << "What is the table size?\n";
            std::cin >> userTableSize;
            testHash -> setTableSize(userTableSize);
            testCH -> setValues(4, 5, userTableSize);
            if(argc > 1){
                std::ifstream file;
                file.open(argv[1]);
                while(file >> data){
                    if(!(testHash -> find(data))){
                        testHash -> insert(data);
                    }
                    if(testCH -> qp_find(data) == -1){
                        testCH -> qp_insert(data);
                    }
                    if(testCH -> dh_find(data) == -1){
                        testCH -> dh_insert(data);
                    }
                }
                std::cout << "Open Hashing:";
                testHash -> print();
                testCH -> print();
            }else{
                std::cout << "You didn't have a file as an argument.\n";
            }
        }else if(choice == 2){
            double stop;
            double sum1, sum2, sum3, sum4, sum5;
            double qpsum1, qpsum2, qpsum3, qpsum4, qpsum5;
            double dhsum1, dhsum2, dhsum3, dhsum4, dhsum5;
            /*double sum2;
            double sum3;
            double sum4;
            double sum5;*/
            int size = 1000003;
            int rand1 = 0.1 * size;
            int rand2 = 0.2 * size;
            int rand3 = 0.3 * size;
            int rand4 = 0.4 * size;
            int rand5 = 0.5 * size;
            int array1[rand1];
            int array2[rand2];
            int array3[rand3];
            int array4[rand4];
            int array5[rand5];

            for(int i = 0; i < 5; i++){
                for(int i = 0; i < rand1; i++){
                    array1[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand2; i++){
                    array2[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand3; i++){
                    array3[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand4; i++){
                    array4[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand5; i++){
                    array5[i] = rand() % (5*size) + 1;
                }
                hash1 -> setTableSize(size);
                hash2 -> setTableSize(size);
                hash3 -> setTableSize(size);
                hash4 -> setTableSize(size);
                hash5 -> setTableSize(size);


                t.start();
                for(int i = 0; i < rand1; i++){
                    hash1 -> insert(array1[i]);
                }
                stop = t.stop();
                sum1 = t.stop() + sum1;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand2; i++){
                    hash2 -> insert(array2[i]);
                }
                stop = t.stop();
                sum2 = t.stop() + sum2;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand3; i++){
                    hash3 -> insert(array3[i]);
                }
                stop = t.stop();
                sum3 = t.stop() + sum3;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand4; i++){
                    hash4 -> insert(array4[i]);
                }
                stop = t.stop();
                sum4 = t.stop() + sum4;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand5; i++){
                    hash5 -> insert(array5[i]);
                }
                stop = t.stop();
                sum5 = t.stop() + sum5;
                //t.printTime(stop);
            }
            std::cout << "Open Hashing Average Build Time (0.1m): " << sum1/5 << "\n";
            std::cout << "Open Hashing Average Build Time (0.2m): " << sum2/5 << "\n";
            std::cout << "Open Hashing Average Build Time (0.3m): " << sum3/5 << "\n";
            std::cout << "Open Hashing Average Build Time (0.4m): " << sum4/5 << "\n";
            std::cout << "Open Hashing Average Build Time (0.5m): " << sum5/5 << "\n";
            std::cout << "---------------------------------------\n";
            sum1 = 0;
            sum2 = 0;
            sum3 = 0;
            sum4 = 0;
            sum5 = 0;

            for(int i = 0; i < 5; i++){
                for(int i = 0; i < rand1; i++){
                    array1[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand2; i++){
                    array2[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand3; i++){
                    array3[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand4; i++){
                    array4[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand5; i++){
                    array5[i] = rand() % (5*size) + 1;
                }

                t.start();
                for(int i = 0; i < rand1; i++){
                    hash1 -> find(array1[i]);
                }
                stop = t.stop();
                sum1 = t.stop() + sum1;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand2; i++){
                    hash2 -> find(array2[i]);
                }
                stop = t.stop();
                sum2 = t.stop() + sum2;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand3; i++){
                    hash3 -> find(array3[i]);
                }
                stop = t.stop();
                sum3 = t.stop() + sum3;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand4; i++){
                    hash4 -> find(array4[i]);
                }
                stop = t.stop();
                sum4 = t.stop() + sum4;
                //t.printTime(stop);

                t.start();
                for(int i = 0; i < rand5; i++){
                    hash5 -> find(array5[i]);
                }
                stop = t.stop();
                sum5 = t.stop() + sum5;
                //t.printTime(stop);
            }
            std::cout << "Open Hashing Average Find Time (0.1m): " << sum1/5 << "\n";
            std::cout << "Open Hashing Average Find Time (0.2m): " << sum2/5 << "\n";
            std::cout << "Open Hashing Average Find Time (0.3m): " << sum3/5 << "\n";
            std::cout << "Open Hashing Average Find Time (0.4m): " << sum4/5 << "\n";
            std::cout << "Open Hashing Average FInd Time (0.5m): " << sum5/5 << "\n";
            std::cout << "--------------------------------------\n";

            for(int i = 0; i < 5; i++){
                for(int i = 0; i < rand1; i++){
                    array1[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand2; i++){
                    array2[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand3; i++){
                    array3[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand4; i++){
                    array4[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand5; i++){
                    array5[i] = rand() % (5*size) + 1;
                }
                ch1 -> setValues(20, 997, size);
                ch2 -> setValues(20, 997, size);
                ch3 -> setValues(20, 997, size);
                ch4 -> setValues(20, 997, size);
                ch5 -> setValues(20, 997, size);

                t.start();
                for(int i = 0; i < rand1; i++){
                    ch1 -> qp_insert(array1[i]);
                }
                stop = t.stop();
                qpsum1 = t.stop() + qpsum1;
                t.start();
                for(int i = 0; i < rand1; i++){
                    ch1 -> dh_insert(array1[i]);
                }
                stop = t.stop();
                dhsum1 = t.stop() + dhsum1;

                t.start();
                for(int i = 0; i < rand2; i++){
                    ch1 -> qp_insert(array2[i]);
                }
                stop = t.stop();
                qpsum2 = t.stop() + qpsum2;
                t.start();
                for(int i = 0; i < rand2; i++){
                    ch2 -> dh_insert(array2[i]);
                }
                stop = t.stop();
                dhsum2 = t.stop() + dhsum2;

                t.start();
                for(int i = 0; i < rand3; i++){
                    ch3 -> qp_insert(array3[i]);
                }
                stop = t.stop();
                qpsum3 = t.stop() + qpsum3;
                t.start();
                for(int i = 0; i < rand3; i++){
                    ch3 -> dh_insert(array3[i]);
                }
                stop = t.stop();
                dhsum3 = t.stop() + dhsum3;

                t.start();
                for(int i = 0; i < rand4; i++){
                    ch4 -> qp_insert(array4[i]);
                }
                stop = t.stop();
                qpsum4 = t.stop() + qpsum4;
                t.start();
                for(int i = 0; i < rand4; i++){
                    ch4 -> dh_insert(array4[i]);
                }
                stop = t.stop();
                dhsum4 = t.stop() + dhsum4;

                t.start();
                for(int i = 0; i < rand5; i++){
                    ch5 -> qp_insert(array5[i]);
                }
                stop = t.stop();
                qpsum5 = t.stop() + qpsum5;
                t.start();
                for(int i = 0; i < rand5; i++){
                    ch5 -> dh_insert(array5[i]);
                }
                stop = t.stop();
                dhsum5 = t.stop() + dhsum5;
            }
            std::cout << "Closed Hashing with QP Average Build Time (0.1m): " << qpsum1/5 << "\n";
            std::cout << "Closed Hashing with QP Average Build Time (0.2m): " << qpsum2/5 << "\n";
            std::cout << "Closed Hashing with QP Average Build Time (0.3m): " << qpsum3/5 << "\n";
            std::cout << "Closed Hashing with QP Average Build Time (0.4m): " << qpsum4/5 << "\n";
            std::cout << "Closed Hashing with QP Average Build Time (0.5m): " << qpsum5/5 << "\n";
            std::cout << "-------------------------------------------------\n";
            std::cout << "Closed Hashing with DH Average Build Time (0.1m): " << dhsum1/5 << "\n";
            std::cout << "Closed Hashing with DH Average Build Time (0.2m): " << dhsum2/5 << "\n";
            std::cout << "Closed Hashing with DH Average Build Time (0.3m): " << dhsum3/5 << "\n";
            std::cout << "Closed Hashing with DH Average Build Time (0.4m): " << dhsum4/5 << "\n";
            std::cout << "Closed Hashing with DH Average Build Time (0.5m): " << dhsum5/5 << "\n";
            std::cout << "-------------------------------------------------\n";

            for(int i = 0; i < 5; i++){
                for(int i = 0; i < rand1; i++){
                    array1[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand2; i++){
                    array2[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand3; i++){
                    array3[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand4; i++){
                    array4[i] = rand() % (5*size) + 1;
                }
                for(int i = 0; i < rand5; i++){
                    array5[i] = rand() % (5*size) + 1;
                }

                t.start();
                for(int i = 0; i < rand1; i++){
                    ch1 -> qp_find(array1[i]);
                }
                stop = t.stop();
                qpsum1 = t.stop() + qpsum1;
                t.start();
                for(int i = 0; i < rand1; i++){
                    ch1 -> dh_find(array1[i]);
                }
                stop = t.stop();
                dhsum1 = t.stop() + dhsum1;

                t.start();
                for(int i = 0; i < rand2; i++){
                    ch1 -> qp_find(array2[i]);
                }
                stop = t.stop();
                qpsum2 = t.stop() + qpsum2;
                t.start();
                for(int i = 0; i < rand2; i++){
                    ch2 -> dh_find(array2[i]);
                }
                stop = t.stop();
                dhsum2 = t.stop() + dhsum2;

                t.start();
                for(int i = 0; i < rand3; i++){
                    ch3 -> qp_find(array3[i]);
                }
                stop = t.stop();
                qpsum3 = t.stop() + qpsum3;
                t.start();
                for(int i = 0; i < rand3; i++){
                    ch3 -> dh_find(array3[i]);
                }
                stop = t.stop();
                dhsum3 = t.stop() + dhsum3;

                t.start();
                for(int i = 0; i < rand4; i++){
                    ch4 -> qp_find(array4[i]);
                }
                stop = t.stop();
                qpsum4 = t.stop() + qpsum4;
                t.start();
                for(int i = 0; i < rand4; i++){
                    ch4 -> dh_find(array4[i]);
                }
                stop = t.stop();
                dhsum4 = t.stop() + dhsum4;

                t.start();
                for(int i = 0; i < rand5; i++){
                    ch5 -> qp_find(array5[i]);
                }
                stop = t.stop();
                qpsum5 = t.stop() + qpsum5;
                t.start();
                for(int i = 0; i < rand5; i++){
                    ch5 -> dh_find(array5[i]);
                }
                stop = t.stop();
                dhsum5 = t.stop() + dhsum5;
            }
            std::cout << "Closed Hashing with QP Average Find Time (0.1m): " << qpsum1/5 << "\n";
            std::cout << "Closed Hashing with QP Average Find Time (0.2m): " << qpsum2/5 << "\n";
            std::cout << "Closed Hashing with QP Average Find Time (0.3m): " << qpsum3/5 << "\n";
            std::cout << "Closed Hashing with QP Average Find Time (0.4m): " << qpsum4/5 << "\n";
            std::cout << "Closed Hashing with QP Average Find Time (0.5m): " << qpsum5/5 << "\n";
            std::cout << "------------------------------------------------\n";
            std::cout << "Closed Hashing with DH Average Find Time (0.1m): " << dhsum1/5 << "\n";
            std::cout << "Closed Hashing with DH Average Find Time (0.2m): " << dhsum2/5 << "\n";
            std::cout << "Closed Hashing with DH Average Find Time (0.3m): " << dhsum3/5 << "\n";
            std::cout << "Closed Hashing with DH Average Find Time (0.4m): " << dhsum4/5 << "\n";
            std::cout << "Closed Hashing with DH Average Find Time (0.5m): " << dhsum5/5 << "\n";
        }else{
            return(0);
        }
    }
}
