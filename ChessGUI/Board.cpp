#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

Board::Board() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			spots[y][x].setX(x);
			spots[y][x].setY(y);
			spots[y][x].setPiece(nullptr);
		}
	}

	resetBoard();
}

Spot Board::getSpot(int x, int y) {
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		std::cerr << "Board index out of bounds";
	}
	else {
		return spots[y][x];
	}

	return Spot();
}

void Board::resetBoard() {
	// create pawns
	for (int col = 0; col < 8; col++) {
		spots[1][col].setPiece(new Pawn(color::WHITE));
		spots[6][col].setPiece(new Pawn(color::BLACK));
	}

	spots[0][0].setPiece(new Rook(color::WHITE));
	spots[0][1].setPiece(new Knight(color::WHITE));
	spots[0][2].setPiece(new Bishop(color::WHITE));
	spots[0][3].setPiece(new Queen(color::WHITE));
	spots[0][4].setPiece(new King(color::WHITE));
	spots[0][5].setPiece(new Bishop(color::WHITE));
	spots[0][6].setPiece(new Knight(color::WHITE));
	spots[0][7].setPiece(new Rook(color::WHITE));

	spots[7][0].setPiece(new Rook(color::BLACK));
	spots[7][1].setPiece(new Knight(color::BLACK));
	spots[7][2].setPiece(new Bishop(color::BLACK));
	spots[7][3].setPiece(new Queen(color::BLACK));
	spots[7][4].setPiece(new King(color::BLACK));
	spots[7][5].setPiece(new Bishop(color::BLACK));
	spots[7][6].setPiece(new Knight(color::BLACK));
	spots[7][7].setPiece(new Rook(color::BLACK));

	// clear empty spaces
	for (int y = 2; y < 6; y++) {
		for (int x = 0; x < 8; x++) {
			spots[y][x].setPiece(nullptr);
		}
	}
}