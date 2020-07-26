#include "main.h"
#include "ChessFrame.h"

IMPLEMENT_APP(ChessApp)

bool ChessApp::OnInit()
{
	ChessFrame *chessFrame = new ChessFrame(wxT("Chess"));
	chessFrame->Show(true);

	return true;
}