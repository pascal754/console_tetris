module Tetrominoes; // :Tetromino;

import CursorBorder;

// check if the current position touches the right side of the wall
bool Tetromino::isEndofRight()
{
	return (x + width - 1) >= wallWidth;
}
