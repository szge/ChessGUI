#include "Queen.h"
#include "Spot.h"
#include "Board.h"

Queen::Queen(Color piece_color) : Piece(piece_color) {
	this->piece_type = PieceType::QUEEN;
};

std::vector<Spot> Queen::getValidMoves(Board board, Spot start) {
	// Queen moves are just the sum of the bishop moves and rook moves.
	// TODO: Is there a better way to do this by making rook and bishop getValidMoves() static and calling them?
	std::vector<Spot> validMoves;
	Spot tempSpot;

	int startX = start.getX();
	int startY = start.getY();
	int x, y;

	int dirs[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

	for (int* dir : dirs) {
		for (int d = 1; d <= 7; d++) {
			x = startX + d * dir[0];
			y = startY + d * dir[1];
			if (0 <= x && x <= 7 && 0 <= y && y <= 7) {
				tempSpot = board.getSpot(x, y);
				if (tempSpot.getPiece() == nullptr) {
					validMoves.push_back(tempSpot);
				}
				else if (tempSpot.getPiece()->getColor() != start.getPiece()->getColor()) {
					validMoves.push_back(tempSpot);
					break;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
	}

	return validMoves;
}