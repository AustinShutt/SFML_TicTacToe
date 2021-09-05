#pragma once
#include "Definitions.h"
#include <SFML/Graphics.hpp>

class GamePiece : public sf::Drawable
{
	sf::Sprite sprite; //Holds the image for an individual game piece

public:
	GamePiece(sf::Texture& texture) //Inherits pre-loaded texture from marker display class and binds it to sprite
	{ 
		sprite.setTexture(texture);
	}

	//fulfills sf::Drawable abstract class requirement by implementing draw function
	void draw(sf::RenderTarget& window, sf::RenderStates states) const { window.draw(sprite); }
	//Set's position of the gamepiece sprite
	void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }
};

