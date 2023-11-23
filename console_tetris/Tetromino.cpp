module;

#include "pch.h"

module Tetrominoes; // :Tetromino;

import CursorBorder;
import Random;

Tetromino::Tetromino()
{
    auto codepoint{ getRandomInt(0x1F354, 0x1F37A) };

    emoji = boost::locale::conv::utf_to_utf<char>(&codepoint, &codepoint + 1);
}

// check if the current position touches the right side of the wall
bool Tetromino::isRightEnd()
{
    return (x + width - 1) >= wallWidth;
}

void Tetromino::moveLeft(const Grid& g)
{
    if (x == 1) // nothing to do
        return;

    --x;

    if (!isClear(g))
    {
        ++x;
        return;
    }

    ++x;
    erase();
    --x;
    draw();
}

void Tetromino::moveRight(const Grid& g)
{
    if (isRightEnd()) // nothing to do
        return;

    ++x;

    if (!isClear(g))
    {
        --x;
        return;
    }

    --x;
    erase();
    ++x;
    draw();
}

bool Tetromino::moveDown(const Grid& g)
{
    ++y;

    if ((y + height > wallHeight) || !isClear(g))
    {
        --y;
        return false;
    }

    --y;
    erase();
    ++y;
    draw();

    return true;
}

void Tetromino::drop(const Grid& g)
{
    erase();

    for (++y; (y <= wallHeight - height) && isClear(g); ++y)
    {
        //step down until the grid is clear for current position
    }

    --y;
    draw();
}

void Tetromino::erase()
{
    printShape("  ");
}