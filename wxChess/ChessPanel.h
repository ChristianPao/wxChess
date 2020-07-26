#pragma once
#include <wx/wx.h>
#include "Board.h"

class ChessPanel : public wxPanel
{
public:
	ChessPanel(wxFrame *parent, Board *board);

private:
	void OnPaint(wxPaintEvent& event);
	void OnLeftMouseDown(wxMouseEvent& event);
	void drawBoard(wxPaintDC& dc);
	void drawPieces(wxPaintDC& dc);
	Piece *ChessPanel::getSelectedPiece(int mouseX, int mouseY);
	Board *board;
};