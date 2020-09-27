#pragma once
#include "Board.fwd.h"
#include "Piece.fwd.h"
#include <wx/wx.h>
#include <unordered_map>
#include "Cell.h"

class Board
{
public:
	Board();
	Piece* getPieceAt(int x, int y);
	// A piece can exist even though it's not on the board anymore (eaten)
	// it's also faster when you want to draw them
	const std::unordered_map<std::string, Piece*>& getPiecesMap();
	Cell* getCellAt(int cellX, int cellY);
	std::string turn;
	std::string getTurn();
	bool isThereEnemy(int cellX, int cellY);
	bool isThereAlly(int cellX, int cellY);
	bool isTherePiece(int cellX, int cellY);
	Piece* getSelectedPiece();
	void setSelectedPiece(Piece* piece);
	void switchTurn();
	void setEnemyIsAI(bool enemyIsAI);
	void eraseAllIllumination();

private:
	std::unordered_map<std::string, Piece*> pieces;
	std::vector<std::vector<Cell*>> cells;
	Piece* selectedPiece;
	bool enemyIsAI;
	void initPieces();
	void initCells();
	
	
};