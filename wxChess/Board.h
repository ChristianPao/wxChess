#pragma once
#include "Pieces.h"
#include <unordered_map>

class Board
{
public:
	Board();
	Piece *getPieceAtCoords(int x, int y);
	const std::unordered_map<std::string, Piece*>& getPiecesMap();
	std::string getSelectedCellType(int x, int y);
	std::string turn;

private:
	std::unordered_map<std::string, Piece*> pieces;
	std::vector<std::vector<std::string>> matrix;
	void initPieces();
	void initMatrix();
};