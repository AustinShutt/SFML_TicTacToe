#pragma once
#include <SFML/Graphics.hpp>

class Background : public sf::Drawable
{
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Background()
	{
		texture.loadFromFile("Assets/Board.png");
		sprite.setTexture(texture);
	}

	void draw(sf::RenderTarget& window, sf::RenderStates states) const
	{
		window.draw(sprite);
	}
};
