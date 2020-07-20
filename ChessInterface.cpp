#include "ChessInterface.h"
#include "Piece.h"

ChessInterface::ChessInterface() {
    
}

Board ChessInterface::getBoard() {
    return board;
}

void ChessInterface::resetBoard() {
    board.resetBoard();
}

Piece* ChessInterface::getPiece(int x, int y) {
    return board.getSpot(x, y).getPiece();
}

Spot ChessInterface::getSpot(int x, int y)
{
    return board.getSpot(x, y);
}

Color ChessInterface::getPlayerColor()
{
    return board.getPlayerColor();
}

bool ChessInterface::move(std::string input) {
    return board.move(input);
}

std::string ChessInterface::printPiece(int x, int y) {
    Piece* piece = board.getSpot(x, y).getPiece();
    std::string output = "";
    if (piece == nullptr) {
        output += "  ";
    }
    else {
        if (piece->getColor() == Color::BLACK) {
            output += 'b';
        }
        else {
            output += 'w';
        }
        output += (std::string) * piece;
    }

    return output;
}

PieceType ChessInterface::getPieceType(int x, int y) {
    return board.getSpot(x, y).getPiece()->getPieceType();
}