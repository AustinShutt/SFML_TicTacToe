#include "Buttons.h"

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	window.draw(sprite);
}

void Button::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
}

void Button::update()
{

}

MenuButton::MenuButton()
{
	texture.loadFromFile("Assets/Menu_Button.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(492.f, 731.f));
}

ResetButton::ResetButton()
{
	texture.loadFromFile("Assets/Reset_Button.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(437.f, 731.f));
}
