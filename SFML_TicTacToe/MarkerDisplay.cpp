#include "MarkerDisplay.h"

MarkerDisplay::MarkerDisplay(BoardArray& board)
	: board(board)
{
	x_Texture.loadFromFile("Assets/X.png");
	o_Texture.loadFromFile("Assets/O.png");
}

void MarkerDisplay::operator+(std::shared_ptr<GamePiece> piece)
{
	pieces.push_back(piece);
}

void MarkerDisplay::updateBoard()
{
	pieces.clear();

	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == 'x')
			{
				std::shared_ptr<GamePiece> piece = std::make_shared<GamePiece>(x_Texture);
				piece->setPosition(sf::Vector2f(j * 200.f, i * 200.f + 100.f));
				*this + piece; //Utilizes trivial operator overloading to add the piece to the display
			}
			if (board[i][j] == 'o')
			{
				std::shared_ptr<GamePiece> piece = std::make_shared<GamePiece>(o_Texture);
				piece->setPosition(sf::Vector2f(j * 200.f, i * 200.f + 100.f));
				*this + piece; ////Utilizes trivial operator overloading to add the piece to the display
			}
		}
	}
}
