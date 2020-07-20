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
	playerColor = Color::WHITE;

	// make sure the heap is happy :)
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			delete spots[row][col].getPiece();
		}
	}

	// create pawns
	for (int col = 0; col < 8; col++) {
		spots[1][col].setPiece(new Pawn(Color::WHITE));
		spots[6][col].setPiece(new Pawn(Color::BLACK));
	}

	spots[0][0].setPiece(new Rook(Color::WHITE));
	spots[0][1].setPiece(new Knight(Color::WHITE));
	spots[0][2].setPiece(new Bishop(Color::WHITE));
	spots[0][3].setPiece(new Queen(Color::WHITE));
	spots[0][4].setPiece(new King(Color::WHITE));
	spots[0][5].setPiece(new Bishop(Color::WHITE));
	spots[0][6].setPiece(new Knight(Color::WHITE));
	spots[0][7].setPiece(new Rook(Color::WHITE));

	spots[7][0].setPiece(new Rook(Color::BLACK));
	spots[7][1].setPiece(new Knight(Color::BLACK));
	spots[7][2].setPiece(new Bishop(Color::BLACK));
	spots[7][3].setPiece(new Queen(Color::BLACK));
	spots[7][4].setPiece(new King(Color::BLACK));
	spots[7][5].setPiece(new Bishop(Color::BLACK));
	spots[7][6].setPiece(new Knight(Color::BLACK));
	spots[7][7].setPiece(new Rook(Color::BLACK));



	// clear empty spaces
	for (int y = 2; y < 6; y++) {
		for (int x = 0; x < 8; x++) {
			spots[y][x].setPiece(nullptr);
		}
	}


	spots[4][4].setPiece(new Bishop(Color::WHITE));
}

Color Board::getPlayerColor() {
	return playerColor;
}


bool Board::move(std::string input) {
	if (input == "0000") {
		// null move, end move
		playerColor = (playerColor == Color::WHITE) ? Color::BLACK : Color::WHITE;
	}
	else {
		// convert input to integer coordinates
		int startX = input[0] - 'a';
		int startY = input[1] - '0' - 1;
		int endX = input[2] - 'a';
		int endY = input[3]  - '0' - 1;
		
		Spot& currentSpot = spots[startY][startX];
		Spot& targetSpot = spots[endY][endX];
		Piece* currentPiece = currentSpot.getPiece();
		Piece* targetPiece = targetSpot.getPiece();

		/* Check preconditions:
			Current spot must contain a valid piece
			Current piece must be the same color as the player moving
			Target spot must either be empty or contain an enemy's piece
			Current piece must be able to move to the target square
		*/

		if (currentPiece != nullptr && (Color) currentPiece->getColor() == playerColor
			&& (targetPiece == nullptr || targetPiece->getColor() != currentPiece->getColor())
			&& !putsKingInCheck(currentSpot, targetSpot)
			&& currentPiece->canMove(*this, currentSpot, targetSpot)) {
			// kill old piece
			delete targetSpot.getPiece();

			if (input.length() >= 5) {
				// pawn promotion
				char promo = input[4];
				if (promo == 'q') {
					targetSpot.setPiece(new Queen((Color)playerColor));
				}
				else if (promo == 'r') {
					targetSpot.setPiece(new Rook((Color)playerColor));
				}
				else if (promo == 'b') {
					targetSpot.setPiece(new Bishop((Color)playerColor));
				}
				else if (promo == 'n') {
					targetSpot.setPiece(new Knight((Color)playerColor));
				}
			}
			else {
				targetSpot.setPiece(currentPiece);
			}

			currentSpot.setPiece(nullptr);

			// switch player color

			playerColor = (playerColor == Color::WHITE) ? Color::BLACK : Color::WHITE;

			return true;
		}
		else {
			// invalid move :(
			return false;
		}
	}

	return false;
}

bool Board::putsKingInCheck(Spot startSpot, Spot endSpot)
{
	// TODO: finish this
	return false;
}
