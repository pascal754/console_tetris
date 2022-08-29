module;

#include <iostream>
#include <string>

module Tetrominoes;// :TetrominoT;

import CursorBorder;
import Grid;


void TetrominoT::printShape(const std::string& sym)
{
	if (state == 0)
	{
		gotoxy(x, y);
		std::cout << sym;
		std::cout << sym;
		std::cout << sym;
		gotoxy(x + 1, y + 1);
		std::cout << sym;
	}
	else if (state == 1) {
		gotoxy(x + 1, y);
		std::cout << sym;
		gotoxy(x, y + 1);
		std::cout << sym;
		std::cout << sym;
		gotoxy(x + 1, y + 2);
		std::cout << sym;
	}
	else if (state == 2) {
		gotoxy(x + 1, y);
		std::cout << sym;
		gotoxy(x, y + 1);
		std::cout << sym;
		std::cout << sym;
		std::cout << sym;
	}
	else {
		gotoxy(x, y);
		std::cout << sym;
		gotoxy(x, y + 1);
		std::cout << sym;
		std::cout << sym;
		gotoxy(x, y + 2);
		std::cout << sym;
	}
}

void TetrominoT::draw()
{
	//printShape("\u2588");
	printShape("T");
}

void TetrominoT::erase()
{
	printShape(" ");
}


void TetrominoT::rotate(const Grid& g)
{
	TetrominoT temp{ *this };

	if (temp.state == 0)
	{
		if (!g.isClear(temp.x, temp.y - 1) || !g.isClear(temp.x, temp.y + 1) || !g.isClear(temp.x + 2, temp.y + 1))
			return;

		--temp.y;
		temp.state = 1;
		temp.width = 2;
		temp.height = 3;
	}
	else if (temp.state == 1) {
		if (!g.isClear(temp.x, temp.y) || !g.isClear(temp.x + 2, temp.y) || !g.isClear(temp.x, temp.y + 2))
			return;

		temp.state = 2;
		temp.width = 3;
		temp.height = 2;
	}
	else if (temp.state == 2) {
		if (!g.isClear(temp.x, temp.y) || !g.isClear(temp.x + 2, temp.y) || !g.isClear(temp.x + 2, temp.y + 2))
			return;

		++temp.x;
		temp.state = 3;
		temp.width = 2;
		temp.height = 3;
	}
	else {
		if (!g.isClear(temp.x + 1, temp.y) || !g.isClear(temp.x + 1, temp.y + 2) || !g.isClear(temp.x - 1, temp.y + 2))
			return;

		--temp.x;
		++temp.y;
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

void TetrominoT::moveLeft(const Grid& g)
{
	if (x == 1) // nothing to do
		return;

	TetrominoT temp{ *this };
	--temp.x;
	if (!temp.isClear(g))
	{
		return;
	}

	erase();
	--x;
	draw();
}

void TetrominoT::moveRight(const Grid& g)
{
	if (isEndofRight()) // nothing to do
		return;

	TetrominoT temp{ *this };
	++temp.x;

	if (!temp.isClear(g))
	{
		return;
	}

	erase();
	++x;
	draw();
}

bool TetrominoT::moveDown(const Grid& g)
{
	TetrominoT temp{ *this };
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


void TetrominoT::drop(const Grid& g)
{
	TetrominoT temp{ *this };

	for (++temp.y; (temp.y <= wallHeight - height) && temp.isClear(g); ++temp.y)
	{
		//step down until the grid is clear for current position
	}
	--temp.y;
	erase();
	*this = temp;
	draw();
}

void TetrominoT::updateGrid(Grid& g)
{
	if (state == 0)
	{
		g.set(x, y);
		g.set(x + 1, y);
		g.set(x + 2, y);
		g.set(x + 1, y + 1);
	}
	else if (state == 1) {
		g.set(x + 1, y);
		g.set(x, y + 1);
		g.set(x + 1, y + 1);
		g.set(x + 1, y + 2);
	}
	else if (state == 2) {
		g.set(x + 1, y);
		g.set(x, y + 1);
		g.set(x + 1, y + 1);
		g.set(x + 2, y + 1);
	}
	else {
		g.set(x, y);
		g.set(x, y + 1);
		g.set(x + 1, y + 1);
		g.set(x, y + 2);
	}
}

bool TetrominoT::isClear(const Grid& g)
{
	if (state == 0)
		return g.isClear(x, y) &&
			g.isClear(x + 1, y) &&
			g.isClear(x + 2, y) &&
			g.isClear(x + 1, y + 1);
	else if (state == 1)
		return g.isClear(x + 1, y) &&
			g.isClear(x, y + 1) &&
			g.isClear(x + 1, y + 1) &&
			g.isClear(x + 1, y + 2);
	else if (state == 2)
		return g.isClear(x + 1, y) &&
			g.isClear(x, y + 1) &&
			g.isClear(x + 1, y + 1) &&
			g.isClear(x + 2, y + 1);
	else
		return g.isClear(x, y) &&
			g.isClear(x, y + 1) &&
			g.isClear(x + 1, y + 1) &&
			g.isClear(x, y + 2);
}
