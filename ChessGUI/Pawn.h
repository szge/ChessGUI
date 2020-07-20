#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	bool firstMove = false;
	bool enPassant = false;
public:
	Pawn(Color piece_color);
	std::vector<Spot> getValidMoves(Board board, Spot start);
	operator std::string() const { return "p"; }
};

