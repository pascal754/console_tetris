module;

#include "pch.h"

export module Tetrominoes:TetrominoI;

import :Tetromino;

// state 0
// I
//(I) // center
// I
// I

// state 1
// I(I)II

export class TetrominoI : public Tetromino
{
public:
    TetrominoI() { state = 0; x = 1; y = 0; width = 1; height = 4; }
    TetrominoI(int cx, int cy) : TetrominoI() { x = cx; y = cy; }
    virtual void rotate(const Grid& g) override;
    virtual void updateGrid(Grid&) override;

protected:
    virtual bool isClear(const Grid&) override;
    virtual void printShape(const std::string& sym) override;
};
