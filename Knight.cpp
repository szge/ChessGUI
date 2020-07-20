#include "Knight.h"
#include "Spot.h"
#include "Board.h"

Knight::Knight(Color piece_color) : Piece(piece_color) {
	this->piece_type = PieceType::KNIGHT;
};

std::vector<Spot> Knight::getValidMoves(Board board, Spot start) {
	std::vector<Spot> validMoves;
	Spot tempSpot;

	int startX = start.getX();
	int startY = start.getY();

	int possibleX[4] = { -2, -1, 1, 2 };
	int dX, dY;
	for (int i = 0; i < 4; i++) {
		dX = possibleX[i];
		dY = 2 / dX;
		if (0 <= startX + dX && startX + dX <= 7 && 0 <= startY + dY && startY + dY <= 7) {
			tempSpot = board.getSpot(startX + dX, startY + dY);
			if ((tempSpot.getPiece() == nullptr || tempSpot.getPiece()->getColor() != start.getPiece()->getColor())
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}
		dY = -1 * dY;
		if (0 <= startX + dX && startX + dX <= 7 && 0 <= startY + dY && startY + dY <= 7) {
			tempSpot = board.getSpot(startX + dX, startY + dY);
			if ((tempSpot.getPiece() == nullptr || tempSpot.getPiece()->getColor() != start.getPiece()->getColor())
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}
	}

	return validMoves;
}