#include "Board.h"

Board::Board()
	:turn{ "white" }
{
	initPieces();
	initMatrix();
}

const std::unordered_map<std::string, Piece*>& Board::getPiecesMap()
{
	return pieces;
}

void Board::initPieces()
{
	
	std::string ids[]{ "Rook_0","Knight_0","Bishop_0","Queen","King","Bishop_1","Knight_1","Rook_1" };

	for (int x = 0; x < 8; x++)
	{
		wxImage image("images/black_pawn.png");
		Piece *pawn = new Pawn(x, 1, wxBitmap::wxBitmap(image), "B_Pawn_" + std::to_string(x));
		pieces[pawn->getId()] = pawn;
	}
	for (int x = 0; x < 8; x++)
	{
		wxImage image("images/white_pawn.png");
		Piece *pawn = new Pawn(x, 6, wxBitmap::wxBitmap(image), "W_Pawn_" + std::to_string(x));
		pieces[pawn->getId()] = pawn;
	}
	std::string colors[] = { "W","B" };
	for (int x = 0; x < 8; x++)
	{
		for (auto& color : colors)
		{
			std::string imageName = color == "W" ? "white" : "black";
			switch (ids[x][0])
			{
			case 'R':
				imageName += "_rook.png"; break;
			case 'K':
				if (ids[x][1] == 'i')
					imageName += "_king.png";
				else
					imageName += "_knight.png";
				break;
			case 'B':
				imageName += "_bishop.png"; break;
			case 'Q':
				imageName += "_queen.png";
			}
			_RPT1(0, "%s\n", imageName.c_str());
			wxImage image("images/"+imageName);
			Piece *pawn = new Pawn(x, color == "W" ? 7 : 0, wxBitmap::wxBitmap(image), color+"_"+ids[x]);
			pieces[pawn->getId()] = pawn;
		}
	}

}

void Board::initMatrix()
{
	std::vector<std::string> empty(8);
	for (int i = 0; i < 8; i++)
		matrix.push_back(empty);
	for (auto& it : pieces)
	{
		Piece *piece=it.second;
		int x = piece->getX();
		int y = piece->getY();
		std::string id = piece->getId();
		matrix[x][y] = id;
	}
}

Piece *Board::getPieceAtCoords(int x, int y)
{
	std::string symbol = matrix[x][y];
	return pieces[symbol];
}

std::string Board::getSelectedCellType(int x, int y)
{
	std::string symbol = matrix[x][y];
	if (symbol == "")
		return "empty";
	if (symbol == "illuminated")
		return "illuminated";
	return "piece";
}