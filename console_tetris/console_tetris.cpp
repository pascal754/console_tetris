// April 27, 2022 by SM
// Tetris game in Windows Terminal

#include "pch.h"

import CursorBorder;
import Grid;
import Tetrominoes;

std::unique_ptr<Tetromino> getRandomTetromino()
{
    std::unique_ptr<Tetromino> tObj{};

    int num{ randomTetromino() };
    if (num == 1)
        tObj = std::make_unique<TetrominoZ>(4, 0);
    else if (num == 2)
        tObj = std::make_unique<TetrominoS>(4, 0);
    else if (num == 3)
        tObj = std::make_unique<TetrominoO>(4, 0);
    else if (num == 4)
        tObj = std::make_unique<TetrominoT>(4, 0);
    else if (num == 5)
        tObj = std::make_unique<TetrominoI>(4, 0);
    else if (num == 6)
        tObj = std::make_unique<TetrominoJ>(4, 0);
    else
        tObj = std::make_unique<TetrominoL>(4, 0);

    return tObj;
}

// freeze the current tetromino and create a new one
// if new one fits the grid then continue the game(return true)
// otherwise finish the game(return false)
bool freezeTetromino(std::unique_ptr<Tetromino>& tObj, std::unique_ptr<Tetromino>& tNext, Grid& grid)
{
    tObj->drop(grid);
    tObj->updateGrid(grid);
    grid.draw();
    grid.deleteFilledRows();


    tNext->setX(tNext->getX() - 15);

    if (tNext->isClear(grid))
    {
        tNext->setX(tNext->getX() + 15);
        tNext->erase();

        tObj = std::move(tNext);
        tObj->setX(tObj->getX() - 15);
        tNext = getRandomTetromino();
        tNext->setX(tNext->getX() + 15);

        tObj->draw();
        tNext->draw();
        return true;
    }

    return false;
}

void clearKeyState()
{
    //clear last escape and arrow keys
    GetAsyncKeyState(VK_ESCAPE);
    GetAsyncKeyState(VK_UP);
    GetAsyncKeyState(VK_LEFT);
    GetAsyncKeyState(VK_RIGHT);
    GetAsyncKeyState(VK_SPACE);
    GetAsyncKeyState(VK_DOWN);
    GetAsyncKeyState(0x50); // P Key
}

// adjust console size to draw border and etc.
void adjustConsoleSize()
{
    CONSOLE_SCREEN_BUFFER_INFOEX consolesize;

    consolesize.cbSize = sizeof(consolesize);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfoEx(hConsole, &consolesize);

    COORD c;
    c.X = 80;
    c.Y = 40;
    consolesize.dwSize = c;

    consolesize.srWindow.Left = 0;
    consolesize.srWindow.Right = 80;
    consolesize.srWindow.Top = 0;
    consolesize.srWindow.Bottom = 40;

    SetConsoleScreenBufferInfoEx(hConsole, &consolesize);
}

int main()
{
    adjustConsoleSize();

    // adjust console size option #2
    /*HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);*/

    system("CLS");

    printBorder();
    Grid grid{}; //initialized with all false, which means not occupied


    auto tObj{ getRandomTetromino() };
    auto tNext{ getRandomTetromino() };

    clearKeyState();

    tObj->draw();
    tNext->setX(tNext->getX() + 15); // move 15 steps to the right and draw it
    tNext->draw();

    int count{};
    bool exitGame{};
    bool paused{};
    auto myWindow{ GetForegroundWindow() };

    while (true)
    {
        if (auto fore{ GetForegroundWindow() }; myWindow == fore)
        {
            if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
            {
                break;
            }
            else if (GetAsyncKeyState(0x50) & 0x01) // P Key
            {
                paused = !paused;
                if (paused)
                {
                    gotoxy(1, -1);
                    std::print("PAUSED");
                }
                else
                {
                    gotoxy(1, -1);
                    std::print("      ");
                }
            }
            else if (GetAsyncKeyState(VK_UP) & 0x01)
            {
                if (!paused)
                {
                    tObj->rotate(grid);
                }
            }
            else if (GetAsyncKeyState(VK_LEFT) & 0x01)
            {
                if (!paused)
                {
                    tObj->moveLeft(grid);
                }
            }
            else if (GetAsyncKeyState(VK_RIGHT) & 0x01)
            {
                if (!paused)
                {
                    tObj->moveRight(grid);
                }
            }
            else if (GetAsyncKeyState(VK_DOWN) & 0x01)
            {
                if (!paused && !tObj->moveDown(grid)
                    && !freezeTetromino(tObj, tNext, grid))
                {
                    exitGame = true;
                    break;
                }
            }
            else if (GetAsyncKeyState(VK_SPACE) & 0x01)
            {
                if (!paused && !freezeTetromino(tObj, tNext, grid))
                {
                    exitGame = true;
                    break;
                }
            }
        } //keyboard

        gotoxy(0, 0);

        //otherwise, cpu usage would be high
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        if (!paused)
        {
            ++count;
            if (count == 20)
            {
                count = 0;
                if (!tObj->moveDown(grid)
                    && !freezeTetromino(tObj, tNext, grid))
                {
                    exitGame = true;
                    break;
                }
            }
        }
    } // while

    gotoxy(0, wallHeight + 1);

    if (exitGame)
    {
        std::println("Game Over");
    }

    while (_kbhit()) _getch(); // clear the keyboard input buffer
}
