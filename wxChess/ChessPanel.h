#pragma once
#include <wx/wx.h>
#include "Board.h"
#include "Pieces.h"
#include <wx/graphics.h>

class ChessPanel : public wxPanel
{
public:
	ChessPanel(wxFrame *parent, Board *board);

private:
	void OnPaint(wxPaintEvent& event);
	void OnLeftMouseDown(wxMouseEvent& event);
	void clearBuffer(wxGraphicsContext *gc);
	void drawBoard(wxGraphicsContext* gc);
	void drawPieces(wxGraphicsContext* gc);
	void drawSelectionScreen(wxGraphicsContext* gc);
	void handleScreenSelection(const wxPoint& point);
	Board *board;
	bool enemySelected;
};