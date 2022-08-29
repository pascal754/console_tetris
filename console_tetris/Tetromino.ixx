module;

#include <string>

export module Tetrominoes:Tetromino;
import Grid;

export class Tetromino
{
public:
	virtual ~Tetromino() = default;
	virtual void draw() = 0;
	virtual void erase() = 0;
	virtual void rotate(const Grid& g) = 0;
	virtual void moveLeft(const Grid& g) = 0;
	virtual void moveRight(const Grid& g) = 0;
	virtual bool moveDown(const Grid& g) = 0;
	virtual void drop(const Grid& g) = 0;
	virtual void updateGrid(Grid&) = 0;
	virtual bool isClear(const Grid&) = 0;
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int cx) { x = cx; }
	void setY(int cy) { y = cy; }

protected:
	virtual bool isEndofRight();
	virtual void printShape(const std::string& sym) = 0;
	
	int state{}; // rotation state, initialized with 0 (default state)

	// x, y: coordinate of top left corner of the box enclosing a tetromino
	int x{}; 
	int y{};

	// width and height of the enclosing box
	int width{};
	int height{};
};
