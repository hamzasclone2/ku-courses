/*
@author: Hamza Hameed
@file: MazeWalker.cpp
@date: November 13, 2015
@brief: tries to find exit of maze using BFS or DFS
*/
#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol,
                       int rows, int cols, Search searchChoice){

    m_maze = mazePtr;
    m_rows = rows;
    m_cols = cols;
    m_searchType = searchChoice;
    m_curPos = Position(startRow, startCol);
    m_startPos = Position(startRow, startCol);
    m_visited = new int*[m_rows];
    for(int i = 0; i < m_rows; i++){
        m_visited[i] = new int[m_cols];
    }
}

MazeWalker::~MazeWalker(){
    for(int i = 0; i < m_rows; i++){
        delete[] m_visited[i];
    }
    delete[] m_visited;
}

bool MazeWalker::walkMaze(){
    if(m_searchType == Search::DFS){
        while(!isGoalReached() && !m_moveStack.empty()){
            move(m_moveStack.top());
            m_moveStack.pop();
            storeValidMoves();
        }
    }
    else if(m_searchType == Search::BFS){
        while(!isGoalReached() && !m_moveQueue.empty()){
            move(m_moveQueue.front());
            m_moveQueue.pop();
            storeValidMoves();
        }
    }
}

const int* const* MazeWalker::getVisited() const{
    return m_visited;
}

int MazeWalker::getVisitedRows() const{
    return m_rows;
}

int MazeWalker::getVisitedCols() const{
    return m_cols;
}

const char* const* MazeWalker::getMaze() const{
    return m_maze;
}

void MazeWalker::storeValidMoves(){
    //NEW UP
    if(m_curPos.getRow() - 1 >= 0 && (m_visited[m_curPos.getRow() - 1][m_curPos.getCol()] == 0) &&
        m_maze[m_curPos.getRow() - 1][m_curPos.getCol()] != 'W'){

        Position up(m_curPos.getRow() - 1, m_curPos.getCol());
        if(m_searchType == Search::DFS){
            m_moveStack.push(up);
        }
        else{
            m_moveQueue.push(up);
        }
    }
    //NEW RIGHT
    if(m_curPos.getCol() + 1 < m_cols && (m_visited[m_curPos.getRow()][m_curPos.getCol() + 1] == 0) &&
        m_maze[m_curPos.getRow()][m_curPos.getCol() + 1] != 'W'){

        Position right(m_curPos.getRow(), m_curPos.getCol() + 1);
        if(m_searchType == Search::DFS){
            m_moveStack.push(right);
        }
        else{
            m_moveQueue.push(right);
        }
    }
    // NEW DOWN
    if(m_curPos.getRow() + 1 < m_rows && (m_visited[m_curPos.getRow() + 1][m_curPos.getCol()] == 0) &&
        m_maze[m_curPos.getRow() + 1][m_curPos.getCol()] != 'W'){

        Position down(m_curPos.getRow() + 1, m_curPos.getCol());
        if(m_searchType == Search::DFS){
            m_moveStack.push(down);
        }
        else{
            m_moveQueue.push(down);
        }
    }
    //LEFT
    if(m_curPos.getCol() - 1 >= 0 && (m_visited[m_curPos.getRow()][m_curPos.getCol() - 1] == 0) &&
        m_maze[m_curPos.getRow()][m_curPos.getCol() - 1] != 'W'){

        Position left(m_curPos.getRow(), m_curPos.getCol() - 1);
        if(m_searchType == Search::DFS){
            m_moveStack.push(left);
        }
        else{
            m_moveQueue.push(left);
        }
    }
}

void MazeWalker::move(Position& p){
    m_curPos = p;
    m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
    m_curStep++;
}

bool MazeWalker::isGoalReached() const{
    if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E'){
        return true;
    }
    return false;
}
