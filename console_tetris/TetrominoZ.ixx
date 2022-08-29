﻿module;

#include <string>

export module Tetrominoes:TetrominoZ;

import :Tetromino;

//state 0
//OO
// OO
//
//state 1
// O
//OO
//O

export class TetrominoZ : public Tetromino
{
public:
	TetrominoZ() { state = 0; x = 1; y = 0; width = 3; height = 2; }
	TetrominoZ(int cx, int cy) : TetrominoZ() {x = cx; y = cy; }
	virtual void draw() override;
	virtual void erase() override;
	virtual void rotate(const Grid& g) override;
	virtual void moveLeft(const Grid& g) override;
	virtual void moveRight(const Grid& g) override;
	virtual bool moveDown(const Grid& g) override;
	virtual void drop(const Grid& g) override;
	virtual void updateGrid(Grid&) override;
	
protected:
	virtual bool isClear(const Grid&) override;
	virtual void printShape(const std::string& sym) override;
};
