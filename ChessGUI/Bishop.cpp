#include "Bishop.h"
#include "Spot.h"
#include "Board.h"

Bishop::Bishop(color piece_color) : Piece(piece_color) {};

bool Bishop::canMove(Board board, Spot start, Spot end) {
	return true;
}