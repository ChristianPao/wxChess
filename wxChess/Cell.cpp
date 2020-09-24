#include "Cell.h"

Cell::Cell()
	:illuminated{ false }, piece{ nullptr }
{
}

Piece* Cell::getPiece()
{
	return piece;
}

bool Cell::isIlluminated()
{
	return illuminated;
}

void Cell::setPiece(Piece* piece)
{
	this->piece = piece;
}

void Cell::turnOff()
{
	illuminated = false;
}

void Cell::turnOn()
{
	illuminated = true;
}

bool Cell::hasPiece()
{
	return piece != nullptr;
}