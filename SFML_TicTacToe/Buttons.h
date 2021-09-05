#pragma once
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "Definitions.h"
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
	bool contains(sf::Vector2f mousePos) { if (sprite.getGlobalBounds().contains(mousePos)) { return true; } return false; }
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

class VersusPlayerButton : public Button
{
public:
	VersusPlayerButton();
};
class VersusComputerButton : public Button
{
public:
	VersusComputerButton();
};
class ExitButton : public Button
{
public:
	ExitButton();
};