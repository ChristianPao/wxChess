#include "ChessFrame.h"
#include "ChessPanel.h"
#include "Board.h"

ChessFrame::ChessFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 640))
{
	Centre();
	wxImage::AddHandler(new wxPNGHandler());
	Board *board = new Board();
	ChessPanel *chessPanel = new ChessPanel(this, board);
}