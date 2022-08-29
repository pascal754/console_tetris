export module CursorBorder;

export
{
	extern const int startX{ 20 };
	extern const int startY{ 5 };
	extern const int wallWidth{ 10 };
	extern const int wallHeight{ 20 };
	void gotoxy(int x, int y);
	void printBorder();
	int randomTetromino();
}
