module;

#include "pch.h"

module Tetrominoes;// :TetrominoI;

import CursorBorder;
import Grid;

void TetrominoI::printShape(const std::string& sym)
{
    if (state == 0)
    {
        gotoxy(x, y);
        std::print("{}", sym);
        gotoxy(x, y + 1);
        std::print("{}", sym);
        gotoxy(x, y + 2);
        std::print("{}", sym);
        gotoxy(x, y + 3);
        std::print("{}", sym);
    }
    else
    {
        gotoxy(x, y);
        std::print("{}", sym);
        std::print("{}", sym);
        std::print("{}", sym);
        std::print("{}", sym);
    }
}

void TetrominoI::draw()
{
    //printShape("\u2588");
    //printShape("I");
    printShape("😍");
}

void TetrominoI::rotate(const Grid& g)
{
    TetrominoI temp{ *this };

    if (temp.state == 0)
    {
        if (!g.isClear(temp.x + 1, temp.y) ||
            !g.isClear(temp.x + 2, temp.y) ||
            !g.isClear(temp.x - 1, temp.y + 2) ||
            !g.isClear(temp.x - 1, temp.y + 3))
            return;

        --temp.x;
        ++temp.y;
        temp.state = 1;
        temp.width = 4;
        temp.height = 1;
    }
    else
    {
        if (!g.isClear(temp.x, temp.y - 1) ||
            !g.isClear(temp.x + 2, temp.y + 1) ||
            !g.isClear(temp.x + 2, temp.y + 2) ||
            !g.isClear(temp.x + 3, temp.y + 1))
            return;

        ++temp.x;
        --temp.y;
        temp.state = 0;
        temp.width = 1;
        temp.height = 4;
    }


    if ((temp.y + temp.height > wallHeight) || !temp.isClear(g))
        return;

    erase();
    *this = std::move(temp);
    draw();
}

void TetrominoI::updateGrid(Grid& g)
{
    if (state == 0)
    {
        g.set(x, y);
        g.set(x, y + 1);
        g.set(x, y + 2);
        g.set(x, y + 3);
    }
    else
    {
        g.set(x, y);
        g.set(x + 1, y);
        g.set(x + 2, y);
        g.set(x + 3, y);
    }
}

bool TetrominoI::isClear(const Grid& g)
{
    if (state == 0)
    {
        return g.isClear(x, y) &&
            g.isClear(x, y + 1) &&
            g.isClear(x, y + 2) &&
            g.isClear(x, y + 3);
    }
    else
    {
        return g.isClear(x, y) &&
            g.isClear(x + 1, y) &&
            g.isClear(x + 2, y) &&
            g.isClear(x + 3, y);
    }
}
