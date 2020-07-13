#include "Spot.h"
#include "Piece.h"

/*
Assumptions:
	0 <= x <= 8
	0 <= y <= 8
*/
Spot::Spot() {
	this->piece = nullptr;
}

Piece* Spot::getPiece() {
	return piece;
}

void Spot::setPiece(Piece* piece) {
	this->piece = piece;
}

int Spot::getX() {
	return x;
}

void Spot::setX(int x) {
	this->x = x;
}

int Spot::getY() {
	return y;
}

void Spot::setY(int y) {
	this->y = y;
}