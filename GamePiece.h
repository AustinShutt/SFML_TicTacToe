#pragma once
#include "Definitions.h"
#include <SFML/Graphics.hpp>

class GamePiece : public sf::Drawable
{

	sf::Texture texture;
	sf::Sprite sprite;

public:
	GamePiece(char piece) {

		if (piece == 'x') { texture.loadFromFile("Assets/X.png"); }
		else { texture.loadFromFile("Assets/O.png"); }

		sprite.setTexture(texture);
	}

	void draw(sf::RenderTarget& window, sf::RenderStates states) const { window.draw(sprite); }
	void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

};

