#include "Bishop.h"
#include "Spot.h"
#include "Board.h"

Bishop::Bishop(Color piece_color) : Piece(piece_color) {
	this->piece_type = PieceType::BISHOP;
};

std::vector<Spot> Bishop::getValidMoves(Board board, Spot start) {
	std::vector<Spot> validMoves;
	Spot tempSpot;

	int startX = start.getX();
	int startY = start.getY();
	int x, y;

	int dirs[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

	for (auto dir : dirs) {
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
