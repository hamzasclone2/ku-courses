/*
@author: Hamza Hameed
@file: Position.cpp
@date: November 13, 2015
@brief: used to represent possible moves in maze
*/
#include "Position.h"
//this constructor may be unnecessary
Position::Position(){

}

Position::Position(int row, int col){
    m_row = row;
    m_col = col;
}

int Position::getRow() const{
    return m_row;
}

int Position::getCol() const{
    return m_col;
}
