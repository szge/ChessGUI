#include "Piece.h"

Piece::Piece(color piece_color) {
	this->piece_color = piece_color;
}

color Piece::getColor() {
	return piece_color;
}

void Piece::setColor(color piece_color) {
	this->piece_color = piece_color;
}

bool Piece::isKilled() {
	return killed;
}

void Piece::setKilled(bool killed) {
	this->killed = killed;
}