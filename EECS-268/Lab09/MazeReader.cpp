/*
@author: Hamza Hameed
@file: MazeReader.cpp
@date: November 13, 2015
@brief: reads maze and gets info on it
*/
#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw(MazeCreationException){
        m_filename = file;
        readMaze();
}

MazeReader::~MazeReader(){
    for(int i = 0; i < m_rows; i++){
        delete[] arr2d[i];
    }
    delete[] arr2d;
}

const char* const* MazeReader::getMaze() const{
    return arr2d;
}

int MazeReader::getCols() const{
    return m_cols;
}

int MazeReader::getRows() const{
    return m_rows;
}

int MazeReader::getStartCol() const{
    return m_startCol;
}

int MazeReader::getStartRow() const{
    return m_startRow;
}

void MazeReader::readMaze() throw(MazeCreationException){
    std::ifstream myInput(m_filename);
    if(myInput.good()){
        myInput >> m_rows;
        myInput >> m_cols;
        myInput >> m_startRow;
        myInput >> m_startCol;
        if(m_rows < 1 || m_cols < 1){
            throw(MazeCreationException("\nMaze size is not valid\n\n"));
        }
        if(m_startRow > m_rows || m_startCol > m_cols){
            throw(MazeCreationException("\nMaze start position is not valid\n\n"));
        }
        arr2d = new char*[m_rows];
        for(int i = 0; i < m_rows; i++){
            arr2d[i] = new char[m_cols];
        }
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                myInput >> arr2d[i][j];
            }
        }
    }
    else{
        throw(MazeCreationException("\nFilename is not valid\n\n"));
    }
}
