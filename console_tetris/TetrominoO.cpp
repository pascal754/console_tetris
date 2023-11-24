module;

#include "pch.h"

module Tetrominoes;// :TetrominoO;

import CursorBorder;
import Grid;

void TetrominoO::printShape(const std::string& sym)
{
    gotoxy(x, y);
    std::print("{}", sym);
    std::print("{}", sym);
    gotoxy(x, y + 1);
    std::print("{}", sym);
    std::print("{}", sym);
}

void TetrominoO::rotate(const Grid& g)
{
}

void TetrominoO::updateGrid(Grid& g)
{
    g.set(x, y);
    g.set(x + 1, y);
    g.set(x, y + 1);
    g.set(x + 1, y + 1);
}

bool TetrominoO::isClear(const Grid& g)
{
    return g.isClear(x, y) &&
        g.isClear(x + 1, y) &&
        g.isClear(x, y + 1) &&
        g.isClear(x + 1, y + 1);
}
