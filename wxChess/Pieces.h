#pragma once
#include <wx/wx.h>

class Piece
{
public:
	/**
	 * Illuminate paths that a particular piece can take (after clicking on it)
	 */
	virtual void illuminatePaths() = 0;
	/// X and Y go from 0 to 7
	int getX(), getY();
	void setX(), setY();
	void setId();
	std::string getId();
	wxBitmap getImage();
	std::string getColor();

protected:
	int x, y;
	std::string id;
	wxBitmap image;
	std::string color;

};

class Pawn : public Piece
{
public:
	Pawn(int x, int y, wxBitmap image, std::string id);
	void illuminatePaths();
};

class Queen : public Piece
{
public:
	Queen(int x, int y, wxBitmap image, std::string id);
	void illuminatePaths();
};

class King : public Piece
{
public:
	King(int x, int y, wxBitmap image, std::string id);
	void illuminatePaths();
};

class Bishop : public Piece
{
public:
	Bishop(int x, int y, wxBitmap image, std::string id);
	void illuminatePaths();
};

class Knight : public Piece
{
public:
	Knight(int x, int y, wxBitmap image, std::string id);
	void illuminatePaths();
};

class Rook : public Piece
{
public:
	Rook(int x, int y, wxBitmap image, std::string id);
	void illuminatePaths();
};