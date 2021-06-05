#pragma once
#include <array>
#include <iostream>
#include "Definitions.h"
#include <SFML/Graphics.hpp>
#include "GamePiece.h"
#include <vector>

class MarkerDisplay : public sf::Drawable
{
	BoardArray& board;
	std::vector<std::shared_ptr<GamePiece>> pieces;
	sf::Texture x_Texture;
	sf::Texture o_Texture;

public:
	MarkerDisplay(BoardArray& board);

	void draw(sf::RenderTarget& window, sf::RenderStates states) const { for (auto itr : pieces) { window.draw(*itr); } }
	void PrintArrayToConsole()
	{
		for (size_t i = 0; i < board.size(); ++i)
		{
			for (size_t j = 0; j < board[0].size(); ++j)
			{
				std::cout << board[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}
	void updateBoard()
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
					pieces.push_back(piece);
				}
				if (board[i][j] == 'o')
				{
					std::shared_ptr<GamePiece> piece = std::make_shared<GamePiece>(o_Texture);
					piece->setPosition(sf::Vector2f(j * 200.f, i * 200.f + 100.f));
					pieces.push_back(piece);
				}
			}
		}
	}
};

