/*
@author: Hamza Hameed
@file: Position.h
@date: November 13, 2015
@brief: used to represent possible moves in maze
*/
#ifndef POSITION_H
#define POSITION_H

class Position{

    public:
    //this constructor may be unnecessary
    Position();

    /*
    @pre: none
    @post: position created with row and col values set
    @return: none
    */
    Position(int row, int col);

    /*
    @pre: none
    @post: none
    @return: row value
    */
    int getRow() const;

    /*
    @pre: none
    @post: none
    @return: col value
    */
    int getCol() const;

    private:

    int m_row;
    int m_col;
};
#endif
