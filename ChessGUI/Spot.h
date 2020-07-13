#pragma once

class Piece;

class Spot {
private:
	Piece* piece;
	int x = 0;
	int y = 0;

public:
	Spot();
	Piece* getPiece();
	void setPiece(Piece* piece);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};