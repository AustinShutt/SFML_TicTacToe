#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <sstream>
#include <iomanip>
#include <iostream>


class ScoreBoard : public sf::Drawable
{
	sf::Font textFont;
	sf::Text x_ScoreText;
	sf::Text o_ScoreText;

	float x_Value;
	float o_Value;
public:

	ScoreBoard();
	void operator>>(float o_Increase);
	void operator<<(float x_Increase);
	void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:

	void initText();
	void setText_X();
	void setText_O();
};

