/*
@author: Hamza Hameed
@file: MazeReader.h
@date: November 13, 2015
@brief: reads maze and gets info on it
*/
#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <string>
#include <fstream>
#include <iostream>
#include "MazeCreationException.h"

class MazeReader{

    public:

    char** arr2d;
    std::string m_filename;
    int m_rows;
    int m_cols;
    int m_startRow;
    int m_startCol;

    /*
    @pre: none
    @post: a MazeReader is created +
           a 2d char arr is allocated with the maze info
    @return:
    */
    MazeReader(std::string file) throw(MazeCreationException);

    /*
    @pre: none
    @post: the maze is deallocated
    @return: none
    */
    ~MazeReader();

    /*
    @pre: file was formatted and read in correctly
    @post: none
    @return: returns pointer to the maza
    */
    const char* const* getMaze() const;

    /*
    @pre: file was formatted and read in correctly
    @post: none
    @return: returns number of columns listed in file
    */
    int getCols() const;

    /*
    @pre: file was formatted and read in correctly
    @post: none
    @return: returns number of rows listed in file
    */
    int getRows() const;

    /*
    @pre: file was formatted and read in correctly
    @post: none
    @return: returns starting column
    */
    int getStartCol() const;

    /*
    @pre: file was formatted and read in correctly
    @post: none
    @return: returns starting row
    */
    int getStartRow() const;

    protected:
    /*
    @pre: file is properly formatted
    @post: the chars representing the maze are stored
    @return: none
    */
    void readMaze() throw(MazeCreationException);
};
#endif
