module;

#include "pch.h"

export module Tetrominoes:Tetromino;

import std;
import Grid;

export class Tetromino
{
public:
    Tetromino();
    virtual ~Tetromino() = default;
    virtual void draw();
    virtual void erase();
    virtual void rotate(const Grid& g) = 0;
    virtual void moveLeft(const Grid& g);
    virtual void moveRight(const Grid& g);
    virtual bool moveDown(const Grid& g);
    virtual void drop(const Grid& g);
    virtual void updateGrid(Grid&) = 0;
    virtual bool isClear(const Grid&) = 0;
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int cx) { x = cx; }
    void setY(int cy) { y = cy; }

protected:
    virtual bool isRightEnd();
    virtual void printShape(const std::string& sym) = 0;

    int state{}; // rotation state, initialized with 0 (default state)

    // x, y: coordinate of the top left corner of a box enclosing a tetromino
    int x{};
    int y{};

    // width and height of the enclosing box
    int width{};
    int height{};

    std::string emoji;
};
