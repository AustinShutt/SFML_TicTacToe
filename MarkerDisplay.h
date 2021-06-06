#pragma once
#include <array>
#include <iostream>
#include "Definitions.h"
#include <SFML/Graphics.hpp>
#include "GamePiece.h"
#include <vector>
#include <memory>

class MarkerDisplay : public sf::Drawable
{
	BoardArray& board;
	std::vector<std::shared_ptr<GamePiece>> pieces;
	sf::Texture x_Texture;
	sf::Texture o_Texture;

public:
	MarkerDisplay(BoardArray& board);

	void draw(sf::RenderTarget& window, sf::RenderStates states) const { for (auto itr : pieces) { window.draw(*itr); } }
	void updateBoard();
	
};

