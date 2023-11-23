module;

#include "pch.h"

module Tetrominoes; // :Tetromino;

import CursorBorder;

Tetromino::Tetromino()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0x1F32D, 0x1F37A);
    auto codepoint{ distrib(gen) };

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