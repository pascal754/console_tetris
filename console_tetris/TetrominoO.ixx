module;

#include "pch.h"

export module Tetrominoes:TetrominoO;

import :Tetromino;

// state 0
// OO
// OO


export class TetrominoO : public Tetromino
{
public:
    TetrominoO() { state = 0; x = 1; y = 0; width = 2; height = 2; }
    TetrominoO(int cx, int cy) : TetrominoO() { x = cx; y = cy; }
    virtual void rotate(const Grid& g) override;
    virtual void updateGrid(Grid&) override;

protected:
    virtual bool isClear(const Grid&) override;
    virtual void printShape(const std::string& sym) override;
};
