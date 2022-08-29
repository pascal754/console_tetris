module;

#include <string>

export module Tetrominoes:TetrominoJ;

import :Tetromino;

// state 0
//  J
//  J
// JJ

// state 1
// J
// JJJ

// state 2
// JJ
// J
// J

// state 3
//  JJJ
//    J

export class TetrominoJ : public Tetromino
{
public:
	TetrominoJ() { state = 0; x = 1; y = 0; width = 2; height = 3; }
	TetrominoJ(int cx, int cy) : TetrominoJ() { x = cx; y = cy; }
	virtual void draw() override;
	virtual void rotate(const Grid& g) override;
	virtual void updateGrid(Grid&) override;

protected:
	virtual bool isClear(const Grid&) override;
	virtual void printShape(const std::string& sym) override;
};
