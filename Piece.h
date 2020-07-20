#pragma once
#include "Color.h"
#include "PieceType.h"
#include "Board.h"
#include "Spot.h"
#include <vector>
#include <cmath>
#include <iostream>

class Board;
class Spot;

class Piece {
private:
	bool killed = false;
	Color piece_color;

protected:
	PieceType piece_type;

public:
	explicit
	Piece(Color piece_Color);
	Color getColor();
	PieceType getPieceType();
	bool isKilled();
	void setKilled(bool killed);
	bool canMove(Board board, Spot start, Spot end);

	// given a list of moves prints their (x,y)
	static void printSpots(std::vector<Spot> a);

	// following functions to be implemented by child classes

	virtual std::vector<Spot> getValidMoves(Board board, Spot start) = 0;

	virtual operator std::string() const { return "."; };
};