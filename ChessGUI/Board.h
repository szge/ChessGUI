#pragma once
#include "Spot.h"
#include <vector>

class Board
{
private:
	Spot spots[8][8];
	std::vector<Piece*> pieces;

public:
	Board();
	Spot getSpot(int x, int y);
	void resetBoard();
};