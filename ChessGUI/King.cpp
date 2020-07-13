#include "King.h"
#include "Spot.h"
#include "Board.h"

King::King(color piece_color) : Piece(piece_color) {};

bool King::canMove(Board board, Spot start, Spot end) {
	return true;
}