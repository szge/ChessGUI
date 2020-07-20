#pragma once
#include "Board.h"
#include "PieceType.h"

class ChessInterface
{
private:
	Board board;

public:
	ChessInterface();
	Board getBoard();
	void resetBoard();
	Piece* getPiece(int x, int y);
	Spot getSpot(int x, int y);
	Color getPlayerColor();
	bool move(std::string input);
	std::string printPiece(int x, int y);
	PieceType getPieceType(int x, int y);
};