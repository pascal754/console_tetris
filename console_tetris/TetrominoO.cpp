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

void TetrominoO::erase()
{
	printShape(" ");
}


void TetrominoO::rotate(const Grid& g)
{
}

void TetrominoO::moveLeft(const Grid& g)
{
	if (x == 1) // nothing to do
		return;

	TetrominoO temp{ *this };
	--temp.x;
	if (!temp.isClear(g))
	{
		return;
	}

	erase();
	--x;
	draw();
}

void TetrominoO::moveRight(const Grid& g)
{
	if (isEndofRight()) // nothing to do
		return;

	TetrominoO temp{ *this };
	++temp.x;
	//temp.printPosition();

	if (!temp.isClear(g))
	{
		return;
	}

	erase();
	++x;
	draw();
	//printPosition();
}

bool TetrominoO::moveDown(const Grid& g)
{
	TetrominoO temp{ *this };
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


void TetrominoO::drop(const Grid& g)
{
	TetrominoO temp{ *this };

	for (++temp.y; (temp.y <= wallHeight - height) && temp.isClear(g); ++temp.y)
	{
		//step down until the grid is clear for current position
	}
	--temp.y;
	erase();
	*this = temp;
	draw();
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
