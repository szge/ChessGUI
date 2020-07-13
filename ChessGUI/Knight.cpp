#include "Knight.h"
#include "Spot.h"
#include "Board.h"

Knight::Knight(color piece_color) : Piece(piece_color) {};

bool Knight::canMove(Board board, Spot start, Spot end) {
	return true;
}