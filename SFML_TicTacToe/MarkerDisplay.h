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
	BoardArray& board; //Local reference to game board
	std::vector<std::shared_ptr<GamePiece>> pieces; //Array of pieces on the board
	sf::Texture x_Texture; //pre-loaded X texture for pieces
	sf::Texture o_Texture; //pre-loaded O texture for pieces

public:
	MarkerDisplay(BoardArray& board); //Constructor
	void operator+(std::shared_ptr<GamePiece> piece); //Fulfills Operator Overloading '+'

	void draw(sf::RenderTarget& window, sf::RenderStates states) const { for (auto itr : pieces) { window.draw(*itr); } }
	void updateBoard(); //Calculates gamepiece positions each time a player move is made
};

