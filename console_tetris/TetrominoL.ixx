module;

#include <string>

export module Tetrominoes:TetrominoL;

import :Tetromino;

// state 0
// L
// L
// LL

// state 1
// LLL
// L

// state 2
// LL
//  L
//  L

// state 3
//    L
//  LLL


export class TetrominoL : public Tetromino
{
public:
	TetrominoL() { state = 0; x = 1; y = 0; width = 2; height = 3; }
	TetrominoL(int cx, int cy) : TetrominoL() { x = cx; y = cy; }
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
