#include "Pawn.h"
#include "Spot.h"
#include "Board.h"

Pawn::Pawn(color piece_color) : Piece(piece_color) {};

bool Pawn::canMove(Board board, Spot start, Spot end) {

	/*if (end.getPiece() == nullptr) {
		return true;
	}

	if (end.getPiece()->isWhite() == this->isWhite()) {
		return false;
	}*/
	return true;
}