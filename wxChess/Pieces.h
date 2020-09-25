#pragma once
#include "Piece.fwd.h"
#include "Board.fwd.h"
#include <wx/wx.h>


class Piece
{
public:
	Piece(int x, int y, wxBitmap image, std::string id);
	/**
	 * Illuminate paths that a particular piece can take (after clicking on it).
	 * I mark the cells as "to be drawn as illuminated", and let the code in
	 * ChessPanel handle the drawing, always.
	 */
	virtual void illuminatePaths(Board* board) = 0;
	/// X and Y go from 0 to 7
	int getCellX(), getCellY();
	void setCellX(int x), setCellY(int y);
	void setId();
	std::string getId();
	wxBitmap getImage();
	std::string getColor();
	void move(int targetX, int targetY, Board* board);
	bool isAlive();
	void setAlive(bool isAlive);

protected:
	int cellX, cellY;
	std::string id;
	wxBitmap image;
	std::string color;
	bool alive;

};

class Pawn : public Piece
{
public:
	Pawn(int cellX, int cellYy, wxBitmap image, std::string id);
	void illuminatePaths(Board* board) override;
};

class Queen : public Piece
{
public:
	Queen(int cellX, int cellY, wxBitmap image, std::string id);
	void illuminatePaths(Board* board) override;
};

class King : public Piece
{
public:
	King(int cellX, int cellY, wxBitmap image, std::string id);
	void illuminatePaths(Board* board) override;
};

class Bishop : public Piece
{
public:
	Bishop(int cellX, int cellY, wxBitmap image, std::string id);
	void illuminatePaths(Board* board) override;
};

class Knight : public Piece
{
public:
	Knight(int cellX, int cellY, wxBitmap image, std::string id);
	void illuminatePaths(Board* board) override;
};

class Rook : public Piece
{
public:
	Rook(int cellX, int cellY, wxBitmap image, std::string id);
	void illuminatePaths(Board* board) override;
};