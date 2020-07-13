#include "Rook.h"
#include "Spot.h"
#include "Board.h"

Rook::Rook(color piece_color) : Piece(piece_color) {};

bool Rook::canMove(Board board, Spot start, Spot end) {
	return true;
}