#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(color piece_color);
	bool canMove(Board board, Spot start, Spot end);
	operator std::string() const { return "r"; }
};

