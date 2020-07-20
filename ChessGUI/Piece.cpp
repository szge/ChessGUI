#include "Piece.h"
#include <algorithm>

Piece::Piece(Color piece_color) {
	this->piece_color = piece_color;
	this->piece_type = PieceType::UNDEFINED;
}

Color Piece::getColor() {
	return piece_color;
}

bool Piece::isKilled() {
	return killed;
}

void Piece::setKilled(bool killed) {
	this->killed = killed;
}

bool Piece::canMove(Board board, Spot start, Spot end)
{
	std::vector<Spot> validMoves = getValidMoves(board, start);

	Piece::printSpots(validMoves);

	bool canMove = false;
	for (unsigned int i = 0; i < validMoves.size(); i++) {

		// equality is not defined between Spot objects so this is the easiest way to do that
		if (validMoves[i].getX() == end.getX() && validMoves[i].getY() == end.getY()) {
			return true;
		}
	}

	return false;
}

void Piece::printSpots(std::vector<Spot> spots)
{
	int size = spots.size();

	for (int i = 0; i < size; i++) {
		std::cout << '(' << spots[i].getX() << ',' << spots[i].getY() << ")\n";
	}
}

PieceType Piece::getPieceType() {
	return piece_type;
}