#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	bool castled = false;

public:
	King(Color piece_color);
	bool hasCastled();
	std::vector<Spot> getValidMoves(Board board, Spot start);
	operator std::string() const { return "k"; }
};

