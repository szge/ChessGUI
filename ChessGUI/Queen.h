#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(color piece_color);
	bool canMove(Board board, Spot start, Spot end);
	operator std::string() const { return "q"; }
};

