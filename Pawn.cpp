#include "Pawn.h"
#include "Spot.h"
#include "Board.h"

Pawn::Pawn(Color piece_color) : Piece(piece_color) {
	this->piece_type = PieceType::PAWN;
};

std::vector<Spot> Pawn::getValidMoves(Board board, Spot start) {
	std::vector<Spot> validMoves;
	Spot tempSpot;

	// for pawns, there is different movement behaviour dependant on color

	int startX = start.getX();
	int startY = start.getY();

	// this code is really fricking ugly and could probably use some Don't Repeat Yourself but im too tired to think
	if (getColor() == Color::WHITE) {
		// pawn is advancing a single square
		tempSpot = board.getSpot(startX, startY + 1);
		if (tempSpot.getPiece() == nullptr && !board.putsKingInCheck(start, tempSpot)) {
			validMoves.push_back(tempSpot);
		}
		
		// pawn can advance two squares on its first move
		// note: it's structured like this to prevent an out of bounds indexing of board.getSpot()
		if (startY == 1) {
			tempSpot = board.getSpot(startX, startY + 2);
			if (board.getSpot(startX, startY + 1).getPiece() == nullptr && tempSpot.getPiece() == nullptr
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}

		// pawn captures on left diagonal
		if (startX > 0) {
			tempSpot = board.getSpot(startX - 1, startY + 1);
			if (tempSpot.getPiece() != nullptr && tempSpot.getPiece()->getColor() != start.getPiece()->getColor()
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}

		// pawn captures on right diagonal
		if (startX < 7) {
			tempSpot = board.getSpot(startX + 1, startY + 1);
			if (tempSpot.getPiece() != nullptr && tempSpot.getPiece()->getColor() != start.getPiece()->getColor()
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}

		// TODO: pawn captures en passant, this is super annoying
		// A pawn if a pawn evades a pawn threat by moving two squares, the threat can still take as if the pawn had moved one square
	}
	else {
		tempSpot = board.getSpot(startX, startY - 1);
		if (tempSpot.getPiece() == nullptr && !board.putsKingInCheck(start, tempSpot)) {
			validMoves.push_back(tempSpot);
		}

		if (startY == 6) {
			tempSpot = board.getSpot(startX, startY - 2);
			if (board.getSpot(startX, startY - 1).getPiece() == nullptr && tempSpot.getPiece() == nullptr
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}

		if (startX > 0) {
			tempSpot = board.getSpot(startX - 1, startY - 1);
			if (tempSpot.getPiece() != nullptr && tempSpot.getPiece()->getColor() != start.getPiece()->getColor()
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}

		if (startX < 7) {
			tempSpot = board.getSpot(startX + 1, startY - 1);
			if (tempSpot.getPiece() != nullptr && tempSpot.getPiece()->getColor() != start.getPiece()->getColor()
				&& !board.putsKingInCheck(start, tempSpot)) {
				validMoves.push_back(tempSpot);
			}
		}
	}



	return validMoves;
}