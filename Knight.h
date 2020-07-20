#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color piece_color);
	std::vector<Spot> getValidMoves(Board board, Spot start);
	operator std::string() const { return "n"; }
};

