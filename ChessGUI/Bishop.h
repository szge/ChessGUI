#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(color piece_color);
	bool canMove(Board board, Spot start, Spot end);
	operator std::string() const { return "b"; }
};

