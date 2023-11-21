module;

#include "pch.h"

export module Grid;

import CursorBorder;

export class Grid
{
public:
    void update();
    void set(int x, int y);
    bool isClear(int, int) const;
    void draw();
    void deleteFilledRows();
private:
    void removeAndCopyRest(int row);
    // true: occupied
    // flase: clear
    bool grid[wallWidth + 1][wallHeight]; // width + 1 for convenience
};

