#pragma once
#include "Spot.h"
#include "Color.h"
#include <vector>
#include <string>

class Board
{
private:
	Spot spots[8][8];
	std::vector<Piece*> pieces;
	Color playerColor = Color::WHITE;

public:
	Board();
	Spot getSpot(int x, int y);
	void resetBoard();
	Color getPlayerColor();

	/* Attempt to perform a move according to an input in long algebraic notation,
	e.g. e2e4, e7e8q
	@return whether or not the move was valid
	*/
	bool move(std::string input);

	/* Checks if moving a piece will put the corresponding King in check.
	Useful as a check to perform before moving a piece.
	@return whether or not a given move puts the corresponding King in check.
	*/
	bool putsKingInCheck(Spot startSpot, Spot endSpot);
};