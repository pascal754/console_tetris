module;

#include "pch.h"

export module Tetrominoes:TetrominoT;

import :Tetromino;

// state 0
// TTT
//  T

// state 1
//  T
// TT
//  T

// state 2
//  T
// TTT

// state 3
//  T
//  TT
//  T

export class TetrominoT : public Tetromino
{
public:
    TetrominoT() { state = 0; x = 1; y = 0; width = 3; height = 2; }
    TetrominoT(int cx, int cy) : TetrominoT() { x = cx; y = cy; }
    virtual void draw() override;
    virtual void rotate(const Grid& g) override;
    virtual void updateGrid(Grid&) override;

protected:
    virtual bool isClear(const Grid&) override;
    virtual void printShape(const std::string& sym) override;
};
