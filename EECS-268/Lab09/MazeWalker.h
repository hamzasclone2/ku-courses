/*
@author: Hamza Hameed
@file: MazeWalker.h
@date: November 13, 2015
@brief: tries to find exit of maze using BFS or DFS
*/
#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <stack>
#include <queue>
#include <iostream>
#include "Position.h"

enum class Search{
    DFS,
    BFS
};

class MazeWalker: public Position{

    public:
    /*
    @pre: the mazePtr is to a valid maza
    @post: a mazeWalker is created, ready to traverse maze using specified order
    @return: none
    */
    MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows,
               int cols, Search searchChoice);

    /*
    @pre: the visited array still exists and has the same dimensions
    @post: the visited array is deallocated
    @return: none
    */
    ~MazeWalker();

    /*
    @pre: the maze is a valid maze
    @post: the maze is traversed until end is reached ae all moves are used
    @return: true if an exit was found, false otherwise
    */
    bool walkMaze();

    /*
    @pre: none
    @post: none
    @return: a const pointer to the visited array
    */
    const int* const* getVisited() const;

    /*
    @pre: none
    @post: none
    @return: returns number of rows in maze
    */
    int getVisitedRows() const;

    /*
    @pre: none
    @post: none
    @return: returns number of columns in maze
    */
    int getVisitedCols() const;

    /*
    @pre: none
    @post: none
    @return: a const pointer to the maze
    */
    const char* const* getMaze() const;

    protected:
    /*
    @pre: the current position is valid
    @post: either stack or queue is loaded with valid moves from current position
    @return: none
    */
    void storeValidMoves();

    /*
    @pre: the position is valid
    @post: the current position is set to p and the position is updated as marked
    @return: none
    */
    void move(Position& p);

    /*
    @pre: none
    @post: none
    @return: true if current position is the exit, false otherwise
    */
    bool isGoalReached() const;

    Search m_searchType;
    const char* const* m_maze;
    int** m_visited;
    int m_rows, m_cols;
    Position m_curPos;
    Position m_startPos;

    std::stack<Position> m_moveStack;
    std::queue<Position> m_moveQueue;

    int m_curStep;
};
#endif
