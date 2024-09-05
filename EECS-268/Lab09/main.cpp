#include <iostream>
#include <fstream>
#include "MazeReader.h"
#include "MazeCreationException.h"
#include "MazeWalker.h"
#include "Position.h"
#include "Test.h"
int main(int argc, char** argv){
    try{
        std::string option = argv[1];
        if(argc == 2){
            if(option == "-test"){
                Test myTester;
                myTester.runTests();
            }
            else{
                std::cout << "\nNot a valid input. Try again.\n\n";
            }
        }
        else if(argc == 3){
            std::string filename = argv[2];
            MazeReader* maze = new MazeReader(filename);
            const char* const* mazePtr = maze -> getMaze();
            int startRow = maze -> getStartRow();
            int startCol = maze -> getStartCol();
            int rows = maze -> getRows();
            int cols = maze -> getCols();
            if(option == "-dfs"){
                Search search = Search::DFS;
                MazeWalker* mazeWalker = new MazeWalker(mazePtr, startRow, startCol,
                                                        rows, cols, search);
                mazeWalker -> walkMaze();
                const int* const* visited = mazeWalker -> getVisited();
                std::cout << "\nStarting Position: " << startRow << ", " << startCol << "\n";
                std::cout << "Size: " << rows << ", " << cols << "\n\n";
                for(int i = 0; i < mazeWalker -> getVisitedRows(); i++){
                    for(int j = 0; j < mazeWalker -> getVisitedCols(); j++){
                        std::cout << visited[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                if(mazeWalker -> walkMaze() == true){
                    std::cout << "\nExit Found!\n";
                }
                else{
                    std::cout << "\nNo Exit!\n";
                }
                delete mazeWalker;
            }
            else if(option == "-bfs"){
                Search search = Search::BFS;
                MazeWalker* mazeWalker = new MazeWalker(mazePtr, startRow, startCol,
                                                        rows, cols, search);
                const int* const* visited = mazeWalker -> getVisited();
                std::cout << "\nStarting Position: " << startRow << ", " << startCol << "\n";
                std::cout << "Size: " << rows << ", " << cols << "\n\n";
                for(int i = 0; i < mazeWalker -> getVisitedRows(); i++){
                    for(int j = 0; j < mazeWalker -> getVisitedCols(); j++){
                        std::cout << visited[i][j] << " ";
                    }
                    std::cout << "\n";
                }
                if(mazeWalker -> walkMaze() == true){
                    std::cout << "\nExit Found!\n";
                }
                else{
                    std::cout << "\nNo Exit!\n";
                }
                delete mazeWalker;
            }
            else{
                std::cout << "\nNot a valid input. Try again.\n\n";
            }
            delete maze;
        }
    }
    catch(MazeCreationException e){
        std::cout << e.what();
    }
    return(0);
}
