module;

#include "pch.h"

export module Tetrominoes:TetrominoI;

import :Tetromino;

// state 0
// I
// I
// I
// I

// state 1
// IIII

export class TetrominoI : public Tetromino
{
public:
	TetrominoI() { state = 0; x = 1; y = 0; width = 1; height = 4; }
	TetrominoI(int cx, int cy) : TetrominoI() { x = cx; y = cy; }
	virtual void draw() override;
	virtual void rotate(const Grid& g) override;
	virtual void updateGrid(Grid&) override;

protected:
	virtual bool isClear(const Grid&) override;
	virtual void printShape(const std::string& sym) override;
};
