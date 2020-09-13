#pragma once
#include "Board.fwd.h"
#include "Piece.fwd.h"
#include <wx/wx.h>
#include <unordered_map>

class Board
{
public:
	Board();
	Piece *getPieceAtCoords(int x, int y);
	const std::unordered_map<std::string, Piece*>& getPiecesMap();
	std::string getSelectedCellType(int x, int y);
	std::vector<std::vector<std::string>> getIlluminations();
	std::string getMatrixElem(int cellX, int cellY);
	std::string turn;
	void setIlluminationOn(int cellX, int cellY);

private:
	std::unordered_map<std::string, Piece*> pieces;
	std::vector<std::vector<std::string>> matrix;
	std::vector<std::vector<std::string>> illuminations;
	void initPieces();
	void initMatrix();
	void initIlluminations();
	
};