module;

#include "pch.h"

module Grid;

import std;
import CursorBorder;

void Grid::update()
{

}

void Grid::set(int x, int y)
{
    if (x < 1 || x > wallWidth || y < 0 || y >= wallHeight)
        return;

    grid[x][y] = true;
}

bool Grid::isClear(int x, int y) const
{
    if (x < 1 || x > wallWidth || y < 0 || y >= wallHeight)
        return false;

    return !grid[x][y];
}

void Grid::draw()
{
    for (int i{ 1 }; i <= wallWidth; ++i)
        for (int j{ 0 }; j < wallHeight; ++j)
        {
            gotoxy(i, j);
            if (grid[i][j])
                std::print("██");
            else
                std::print("  ");

        }
}

void Grid::deleteFilledRows()
{
    int i{ wallHeight }; // start from the bottom

    while (i > 0)
    {
        bool filled{ grid[1][i] }; //initialize with the first element. Remember grid start from 1

        for (int j{ 2 }; j <= wallWidth && filled; ++j)
        {
            filled = filled && grid[j][i];
        }

        if (filled)
        {
            removeAndCopyRest(i);
            draw(); // draw grid and start from the same row again
        }
        else
        {
            --i;
        }
    }
}


//remove the current row and copy the upper values
void Grid::removeAndCopyRest(int row)
{
    for (int i{ row }; i > 0; --i)
    {
        for (int j{ 1 }; j <= wallWidth; ++j)
        {
            grid[j][i] = grid[j][i - 1];
        }
    }
}