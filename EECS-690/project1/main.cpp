//#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <fstream>
#include "Barrier.h"

std::mutex coutMutex; //mutex for printing
Barrier* b = new Barrier(); //stops any train from going ahead before others have moved
int numTrains; //number of total trains
int numStations; //number of total stations
bool allFinished = false; //checks whether all trains are done or not
int numFinished = 0; //number of trains that have completed their route
int* timestepFinished; //what timestep that the train has finished on

void print(int timestep, int route[], int trainNum, int step){
    coutMutex.lock();
    char letter = trainNum % 26 + 'A';
    std::cout << "At time step: " << timestep << " train " << letter
              << " is going from station " << route[step-1] << " to station "
              << route[step] << "\n";
    coutMutex.unlock();
}

void finalPrint(){ //prints out when every train is finished
    char letter;
    for(int i = 0; i < numTrains; i++){
        letter = i % 26 + 'A';
        std::cout << "Train " << letter << " completed its route at time step "
                  << timestepFinished[i] << "\n";
    }
    exit(0); //terminates the program
}

//each time step of the program
void step(int route[], int trainNum, int numStops){
    int timestep = 0;
    int step = 1; //starts each train at its first value
    char letter = trainNum % 26 + 'A';
    while(allFinished == false){ //while trains are still moving
        if(step != numStops){ //not at the last stop
            print(timestep, route, trainNum, step);
            step++;
            timestep++;
            if(step == numStops){ //if at the last stop
                numFinished++; //incread number of trains that are done
                timestepFinished[trainNum] = timestep-1;
            }
        }
        if(numFinished == numTrains){
            allFinished = true;
            std::cout << "Simulation complete.\n\n";
            finalPrint();
        }
        b -> barrier(numTrains);
    }
}

int main(int argc, char* argv[]){
    if(argc != 2){ //if no data file is passed in
        std::cout << "You need to pass in a data file.\n";
        return 0;
    }
    std::cout << "All aboard!\n";
    std::ifstream file;
    file.open("data.txt");
    file >> numTrains;
    file >> numStations;
    int* trains[numTrains]; //array that holds each train

    std::thread** t = new std::thread*[numTrains];

    int numStops; //number of stops for each train
    int val; //specific stops that make up a route
    int* routes; //route being passed into each thread
    int* routeNums = new int[numTrains]; //array of # of stops for all trains
    timestepFinished = new int[numTrains];

    for(int i = 0; i < numTrains; i++){
        file >> numStops;
        routeNums[i] = numStops;
        routes = new int[numStops]; //array that holds each train's route
        for(int j = 0; j < numStops; j++){
            file >> val;
            routes[j] = val;
        }
        trains[i] = routes;
    }

    for(int i = 0; i < numTrains; i++){ //fires off all the threads
        t[i] = new std::thread(step, trains[i], i, routeNums[i]);
    }

    for(int i = 0; i < numTrains; i++){
        t[i] -> join();
    }
    return(0);
}
