module;

#include "pch.h"

module CursorBorder;

import Random;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = startX + 2 * x; // Emoji occupies two columns.
    coord.Y = startY + y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printBorder()
{
    for (int i{}; i < wallHeight; ++i)
    {
        gotoxy(0, i);
        std::print("🧱"); //║
        gotoxy(wallWidth + 1, i);
        std::print("🧱"); //║
    }
    gotoxy(0, wallHeight);
    std::print("🧱"); //╚

    for (int i{ 1 }; i <= wallWidth; ++i)
        std::print("🧱"); //═

    std::print("🧱"); //╝
    gotoxy(15, -1);
    std::print("Next");
}

int randomTetromino()
{
    return getRandomInt(1, 7);
}
