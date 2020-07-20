#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Color piece_color);
	std::vector<Spot> getValidMoves(Board board, Spot start);
	operator std::string() const { return "r"; }
};

