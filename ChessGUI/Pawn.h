#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	bool firstMove = false;
public:
	Pawn(color piece_color);
	bool canMove(Board board, Spot start, Spot end);
	operator std::string() const { return "p"; }
};

