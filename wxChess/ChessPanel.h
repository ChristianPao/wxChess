#pragma once
#include <wx/wx.h>

class ChessPanel : public wxPanel
{
public:
	ChessPanel(wxFrame *parent);

protected:
	void OnPaint(wxPaintEvent& event);

private:
	void drawBoard(wxPaintDC& dc);
};