#include "ChessFrame.h"
#include "ChessPanel.h"

ChessFrame::ChessFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 640))
{
	Centre();
	ChessPanel* chessPanel = new ChessPanel(this);
}