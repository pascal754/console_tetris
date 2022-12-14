module;

#include <Windows.h>
#include <iostream>
#include <random>
#include <functional>

module CursorBorder;


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = startX + x;
	coord.Y = startY + y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printBorder()
{
	for (int i{}; i < wallHeight; ++i)
	{
		gotoxy(0, i);
		std::cout << "\u2551"; // '║'
		gotoxy(wallWidth + 1, i);
		std::cout << "\u2551";
	}
	gotoxy(0, wallHeight);
	std::cout << "\u255A"; // '╚'

	for (int i{ 1 }; i <= wallWidth; ++i)
		std::cout << "\u2550"; // '═'

	std::cout << "\u255D"; // '╝'
	gotoxy(15, -1);
	std::cout << "Next";
}

int randomTetromino()
{
	//random number generation option #1
	//std::random_device seeder; // True random number generator to obtain a seed (slow)
	//std::default_random_engine generator{ seeder() }; // Efficient pseudo-random generator
	//std::uniform_int_distribution distribution{ 1, 2 }; // Generate in [0, max) interval
	//return std::bind(distribution, generator);

	//random number generation option #2
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(1, 7);

	return distrib(gen);
}
