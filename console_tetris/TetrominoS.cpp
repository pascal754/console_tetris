module;

#include "pch.h"

module Tetrominoes;// :TetrominoS;

import CursorBorder;
import Grid;


void TetrominoS::printShape(const std::string& sym)
{
	if (state == 0)
	{
		gotoxy(x + 1, y);
		std::cout << sym;
		std::cout << sym;
		gotoxy(x, y + 1);
		std::cout << sym;
		std::cout << sym;
	}
	else
	{
		gotoxy(x, y);
		std::cout << sym;
		gotoxy(x, y + 1);
		std::cout << sym;
		std::cout << sym;
		gotoxy(x + 1, y + 2);
		std::cout << sym;
	}
}


void TetrominoS::draw()
{
	//printShape("\u2588");
	printShape("S");
}

// 1. test collision
// 2. erase the current shape, set roatation state, and redraw
void TetrominoS::rotate(const Grid& g)
{
	TetrominoS temp{ *this };

	if (temp.state == 0)
	{
		if (!g.isClear(temp.x + 2, temp.y + 1) || !g.isClear(temp.x + 2, temp.y + 2))
			return;

		temp.state = 1;
		temp.width = 2;
		temp.height = 3;
	}
	else {
		if (!g.isClear(temp.x, temp.y + 2))
			return;

		temp.state = 0;
		temp.width = 3;
		temp.height = 2;
	}

	if ((temp.y + temp.height > wallHeight) || !temp.isClear(g))
		return;

	erase();
	*this = temp;
	draw();
}

void TetrominoS::updateGrid(Grid& g)
{
	if (state == 0)
	{
		g.set(x + 1, y);
		g.set(x + 2, y);
		g.set(x, y + 1);
		g.set(x + 1, y + 1);
	}
	else {
		g.set(x, y);
		g.set(x, y + 1);
		g.set(x + 1, y + 1);
		g.set(x + 1, y + 2);
	}
}

bool TetrominoS::isClear(const Grid& g)
{
	if (state == 0)
	{
		return g.isClear(x + 1, y) &&
			g.isClear(x + 2, y) &&
			g.isClear(x, y + 1) &&
			g.isClear(x + 1, y + 1);
	}
	else {
		return g.isClear(x, y) &&
			g.isClear(x, y + 1) &&
			g.isClear(x + 1, y + 1) &&
			g.isClear(x + 1, y + 2);
	}
}
