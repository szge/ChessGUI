#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Color piece_color);
	std::vector<Spot> getValidMoves(Board board, Spot start);
	operator std::string() const { return "b"; }
};

