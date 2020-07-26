#include "ChessPanel.h"

ChessPanel::ChessPanel(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE)
{

	Connect(wxEVT_PAINT, wxPaintEventHandler(ChessPanel::OnPaint));
}

void ChessPanel::OnPaint(wxPaintEvent& event)
{
	// dc stands for "device context"
	// This is where I'm gonna paint board and pieces
	//wxBufferedPaintDC ?
	wxPaintDC dc(this);
	
	drawBoard(dc);
}

void ChessPanel::drawBoard(wxPaintDC& dc)
{
	const wxColor white = wxColor(255, 255, 255);
	const wxColor black = wxColor(0, 0, 0);
	dc.SetPen(*wxTRANSPARENT_PEN);

	// I need to compute these like this 'cause they're not the same
	// to when you build the Frame
	const int cellLenX = GetClientSize().GetWidth() / 8;
	const int cellLenY = GetClientSize().GetHeight() / 8;

	for (int y = 0; y<8; y++)
		for (int x = 0; x < 8; x++)
		{
			if ((x + y) % 2 == 0)
				dc.SetBrush(wxBrush(white));
			else
				dc.SetBrush(wxBrush(black));
			dc.DrawRectangle(x*cellLenX, y*cellLenY, cellLenX, cellLenY);
		}
}