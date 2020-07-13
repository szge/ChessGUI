#pragma once
#include <iostream>

class Board;
class Spot;

enum class color{WHITE, BLACK};

class Piece {
private:
	bool killed = false;
	color piece_color;

public:
	explicit
	Piece(color piece_color);
	color getColor();
	void setColor(color piece_color);
	bool isKilled();
	void setKilled(bool killed);
	// to be implemented by child classes
	virtual bool canMove(Board board, Spot start, Spot end) = 0;
	virtual operator std::string() const { return "."; };
};