#include "Buttons.h"

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	window.draw(sprite);
}

void Button::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		sf::Vector2i worldPos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePos = window.mapPixelToCoords(worldPos);

		if (isWithin(mousePos))
		{
			sprite.setScale(sf::Vector2f(1.2f, 1.2f));
		}
		else
		{
			sprite.setScale(sf::Vector2f(1.0f, 1.0f));
		}
	}
}

void Button::update()
{

}

MenuButton::MenuButton()
{
	texture.loadFromFile("Assets/Menu_Button.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(sf::Vector2f(492.f, 751.f));
	
}

ResetButton::ResetButton()
{
	texture.loadFromFile("Assets/Reset_Button.png");
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(sf::Vector2f(432.f, 751.f));
}
