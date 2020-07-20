#include "King.h"
#include "Spot.h"
#include "Board.h"

King::King(Color piece_color) : Piece(piece_color) {
	this->piece_type = PieceType::KING;
};

std::vector<Spot> King::getValidMoves(Board board, Spot start) {
	std::vector<Spot> validMoves;
	Spot tempSpot;

	int startX = start.getX();
	int startY = start.getY();

	for (int dY = -1; dY <= 1; dY++) {
		for (int dX = -1; dX <= 1; dX++) {
			// exclude the square the King is currently on
			if ((dX != 0 || dY != 0) && 0 <= startX + dX && startX + dX <= 7
				&& 0 <= startY + dY && startY + dY <= 7) {
				tempSpot = board.getSpot(startX + dX, startY + dY);
				if (tempSpot.getPiece() == nullptr && !board.putsKingInCheck(start, tempSpot)) {
					validMoves.push_back(tempSpot);
				}
				else if (tempSpot.getPiece()->getColor() != start.getPiece()->getColor() && !board.putsKingInCheck(start, tempSpot)) {
					validMoves.push_back(tempSpot);
					break;
				}
				else {
					break;
				}
			}
		}
	}

	return validMoves;
}