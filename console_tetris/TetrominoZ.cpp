module;

#include <iostream>
#include <string>

module Tetrominoes; // :TetrominoZ;

import CursorBorder;
import Grid;


void TetrominoZ::printShape(const std::string& sym)
{
	if (state == 0)
	{
		gotoxy(x, y);
		std::cout << sym;
		std::cout << sym;
		gotoxy(x + 1, y + 1);
		std::cout << sym;
		std::cout << sym;
	}
	else
	{
		gotoxy(x + 1, y);
		std::cout << sym;
		gotoxy(x, y + 1);
		std::cout << sym;
		std::cout << sym;
		gotoxy(x, y + 2);
		std::cout << sym;
	}
}


void TetrominoZ::draw()
{
	//printShape("\u2588");
	printShape("Z");
}

void TetrominoZ::erase()
{
	printShape(" ");
}

void TetrominoZ::rotate(const Grid& g)
{
	TetrominoZ temp{ *this };

	if (temp.state == 0)
	{
		if (!g.isClear(temp.x + 1, temp.y + 2) || !g.isClear(temp.x + 2, temp.y + 2))
			return;

		temp.state = 1;
		temp.width = 2;
		temp.height = 3;
	}
	else {
		if (!g.isClear(x + 2, y))
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

void TetrominoZ::moveLeft(const Grid& g)
{
	if (x == 1) // nothing to do
		return;

	TetrominoZ temp{ *this };
	--temp.x;
	if (!temp.isClear(g))
	{
		return;
	}

	erase();
	--x;
	draw();
}

void TetrominoZ::moveRight(const Grid& g)
{
	if (isEndofRight()) // nothing to do
		return;

	TetrominoZ temp{ *this };
	++temp.x;

	if (!temp.isClear(g))
	{
		return;
	}

	erase();
	++x;
	draw();
}

bool TetrominoZ::moveDown(const Grid& g)
{
	TetrominoZ temp{ *this };
	++temp.y;

	if ((temp.y + temp.height > wallHeight) || !temp.isClear(g))
	{
		return false;
	}

	erase();
	++y;
	draw();

	return true;
}


void TetrominoZ::drop(const Grid& g)
{
	TetrominoZ temp{ *this };

	for (++temp.y; (temp.y <= wallHeight - height) && temp.isClear(g); ++temp.y)
	{
		//step down until the grid is clear for current position
	}
	--temp.y;
	erase();
	*this = temp;
	draw();
}

void TetrominoZ::updateGrid(Grid& g)
{
	if (state == 0)
	{
		g.set(x, y);
		g.set(x + 1, y);
		g.set(x + 1, y + 1);
		g.set(x + 2, y + 1);
	}
	else {
		g.set(x + 1, y);
		g.set(x, y + 1);
		g.set(x + 1, y + 1);
		g.set(x, y + 2);
	}
}

bool TetrominoZ::isClear(const Grid& g)
{
	if (state == 0)
	{
		return g.isClear(x, y) &&
			g.isClear(x + 1, y) &&
			g.isClear(x + 1, y + 1) &&
			g.isClear(x + 2, y + 1);
	}
	else {
		return g.isClear(x + 1, y) &&
			g.isClear(x, y + 1) &&
			g.isClear(x + 1, y + 1) &&
			g.isClear(x, y + 2);
	}
}
