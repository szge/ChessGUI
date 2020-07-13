#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	bool castled = false;

public:
	King(color piece_color);
	bool canMove(Board board, Spot start, Spot end);
	bool hasCastled();
	operator std::string() const { return "k"; }
};

