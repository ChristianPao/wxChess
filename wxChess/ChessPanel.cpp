#include "ChessPanel.h"

ChessPanel::ChessPanel(wxFrame *parent, Board *board)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE),
	board{ board }
{

	Connect(wxEVT_PAINT, wxPaintEventHandler(ChessPanel::OnPaint));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(ChessPanel::OnLeftMouseDown));
}

void ChessPanel::OnPaint(wxPaintEvent& event)
{
	// dc stands for "device context"
	// This is where I'm gonna paint board and pieces
	//wxBufferedPaintDC ?
	wxPaintDC dc(this);
	drawBoard(dc);
	drawPieces(dc);
}

void ChessPanel::OnLeftMouseDown(wxMouseEvent& event)
{
	auto pos = event.GetPosition();
	const int cellLenX = GetClientSize().GetWidth() / 8;
	const int cellLenY = GetClientSize().GetHeight() / 8;
	int x = (int)(pos.x / cellLenX);
	int y = (int)(pos.y / cellLenY);

	std::string type = board->getSelectedCellType(x, y);
	if (type == "piece")
	{
		auto piece = getSelectedPiece(pos.x, pos.y);
		piece->illuminatePaths();
	}
	else if (type == "illuminated")
	{

	}
	else
	{
		// Erase illumination
	}
}

Piece *ChessPanel::getSelectedPiece(int x, int y)
{
	Piece *piece = board->getPieceAtCoords(x, y);
	_RPT1(0, "%s\n", piece->getId().c_str());
	return piece;
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

void ChessPanel::drawPieces(wxPaintDC& dc)
{
	const int cellLenX = GetClientSize().GetWidth() / 8;
	const int cellLenY = GetClientSize().GetHeight() / 8;
	auto piecesMap = board->getPiecesMap();
	std::string a = "Begin";
	_RPT1(0, "%s\n", a.c_str());
	for (auto& it : piecesMap)
	{
		Piece *piece = it.second;
		dc.DrawBitmap(piece->getImage(), piece->getX()*cellLenX+10, piece->getY()*cellLenY);
	}
	_RPT1(0, "%s\n", "Stop drawing pieces");
}