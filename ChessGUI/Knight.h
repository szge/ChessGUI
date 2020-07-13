#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(color piece_color);
	bool canMove(Board board, Spot start, Spot end);
	operator std::string() const { return "n"; }
};

