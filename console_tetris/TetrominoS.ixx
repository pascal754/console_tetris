module;

#include <string>

export module Tetrominoes:TetrominoS;

import :Tetromino;

// state 0
//  SS
// SS
//

//state 1
// S
// SS
//  S
export class TetrominoS : public Tetromino
{
public:
	TetrominoS() { state = 0; x = 1; y = 0; width = 3; height = 2; }
	TetrominoS(int cx, int cy) : TetrominoS() { x = cx; y = cy; }
	virtual void draw() override;
	virtual void rotate(const Grid& g) override;
	virtual void updateGrid(Grid&) override;

protected:
	virtual bool isClear(const Grid&) override;
	virtual void printShape(const std::string& sym) override;
};
