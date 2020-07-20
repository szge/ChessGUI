#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Color piece_color);
	std::vector<Spot> getValidMoves(Board board, Spot start);
	operator std::string() const { return "q"; }
};

