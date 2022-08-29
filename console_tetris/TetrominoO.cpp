module;

#include <iostream>
#include <string>

module Tetrominoes;// :TetrominoO;

import CursorBorder;
import Grid;


void TetrominoO::printShape(const std::string& sym)
{
	gotoxy(x, y);
	std::cout << sym;
	std::cout << sym;
	gotoxy(x, y + 1);
	std::cout << sym;
	std::cout << sym;
}


void TetrominoO::draw()
{
	//printShape("\u2588");
	printShape("O");
}

void TetrominoO::rotate(const Grid& g)
{
}

void TetrominoO::updateGrid(Grid& g)
{
	g.set(x, y);
	g.set(x + 1, y);
	g.set(x, y + 1);
	g.set(x + 1, y + 1);
}

bool TetrominoO::isClear(const Grid& g)
{
	return g.isClear(x, y) &&
		g.isClear(x + 1, y) &&
		g.isClear(x, y + 1) &&
		g.isClear(x + 1, y + 1);
}
