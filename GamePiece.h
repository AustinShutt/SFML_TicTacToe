#pragma once
#include "Definitions.h"
#include <SFML/Graphics.hpp>

class GamePiece : public sf::Drawable
{
	sf::Sprite sprite;

public:
	GamePiece(sf::Texture& texture) {

		sprite.setTexture(texture);
	}

	void draw(sf::RenderTarget& window, sf::RenderStates states) const { window.draw(sprite); }
	void setPosition(sf::Vector2f pos) { sprite.setPosition(pos); }

};

