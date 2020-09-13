#include "Pieces.h"
#include "Board.h"

Piece::Piece(int cellX, int cellY, wxBitmap image, std::string id)
{
	this->cellX = cellX;
	this->cellY = cellY;
	this->image = image;
	this->id = id;
	this->color = id[0] == 'W' ? "white" : "black";
}

std::string Piece::getId()
{
	return id;
}

int Piece::getCellX()
{
	return cellX;
}

int Piece::getCellY()
{
	return cellY;
}

wxBitmap Piece::getImage()
{
	return image;
}

std::string Piece::getColor()
{
	return color;
}

Pawn::Pawn(int cellX, int cellY, wxBitmap image, std::string id)
	: Piece(cellX, cellY, image, id)
{

}

void Pawn::illuminatePaths(Board* board)
{
	short sign = 1;
	if (color == "black")
		sign = -1;
	if ((cellY == 6 && color=="white") || (cellY == 1 && color == "black"))
	{
		board->setIlluminationOn(cellX, cellY - 1*sign);
		board->setIlluminationOn(cellX, cellY - 2*sign);
	}
	else
	{
		for(int y=cellY; board->getMatrixElem(cellX, cellY)=="";y=y-1*sign)
			board->setIlluminationOn(cellX, y);
	}
}

Rook::Rook(int cellX, int cellY, wxBitmap image, std::string id)
	: Piece(cellX, cellY, image, id)
{

}

void Rook::illuminatePaths(Board* board)
{

}

Knight::Knight(int cellX, int cellY, wxBitmap image, std::string id)
	: Piece(cellX, cellY, image, id)
{

}

void Knight::illuminatePaths(Board* board)
{

}

Bishop::Bishop(int cellX, int cellY, wxBitmap image, std::string id)
	: Piece(cellX, cellY, image, id)
{

}

void Bishop::illuminatePaths(Board* board)
{

}

Queen::Queen(int cellX, int cellY, wxBitmap image, std::string id)
	: Piece(cellX, cellY, image, id)
{

}

void Queen::illuminatePaths(Board* board)
{

}

King::King(int cellX, int cellY, wxBitmap image, std::string id)
	: Piece(cellX, cellY, image, id)
{

}

void King::illuminatePaths(Board* board)
{

}