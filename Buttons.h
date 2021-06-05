#pragma once
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include <iostream>

class Button : public sf::Drawable, public EventHandler
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
	virtual void update();
	bool isClicked(sf::Vector2f mousePos) { if (sprite.getGlobalBounds().contains(mousePos)) { return true; } return false; }
	sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); }

};


class MenuButton : public Button //Satisfies Inheritance Requirement
{
public:
	MenuButton();
};

class ResetButton : public Button
{
public:
	ResetButton();
};