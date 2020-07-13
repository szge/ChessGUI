#include "Queen.h"
#include "Spot.h"
#include "Board.h"

Queen::Queen(color piece_color) : Piece(piece_color) {};

bool Queen::canMove(Board board, Spot start, Spot end) {
	return true;
}