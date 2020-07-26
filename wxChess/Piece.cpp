#include "Pieces.h"

std::string Piece::getId()
{
	return id;
}

int Piece::getX()
{
	return x;
}

int Piece::getY()
{
	return y;
}

wxBitmap Piece::getImage()
{
	return image;
}

std::string Piece::getColor()
{
	return color;
}

Pawn::Pawn(int x, int y, wxBitmap image, std::string id)
{
	this->x = x;
	this->y = y;
	this->image = image;
	this->id = id;
	this->color = id[0] == 'W' ? "white" : "black";
	//this->board = board;
}

void Pawn::illuminatePaths()
{

}

Rook::Rook(int x, int y, wxBitmap image, std::string id)
{
	this->x = x;
	this->y = y;
	this->image = image;
	this->id = id;
}

void Rook::illuminatePaths()
{

}

Knight::Knight(int x, int y, wxBitmap image, std::string id)
{
	this->x = x;
	this->y = y;
	this->image = image;
	this->id = id;
}

void Knight::illuminatePaths()
{

}

Bishop::Bishop(int x, int y, wxBitmap image, std::string id)
{
	this->x = x;
	this->y = y;
	this->image = image;
	this->id = id;
}

void Bishop::illuminatePaths()
{

}

Queen::Queen(int x, int y, wxBitmap image, std::string id)
{
	this->x = x;
	this->y = y;
	this->image = image;
	this->id = id;
}

void Queen::illuminatePaths()
{

}

King::King(int x, int y, wxBitmap image, std::string id)
{
	this->x = x;
	this->y = y;
	this->image = image;
	this->id = id;
}

void King::illuminatePaths()
{

}