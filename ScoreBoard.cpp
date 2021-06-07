#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
	:x_Value(0.f), o_Value(0.f)
{
	initText();
}

void ScoreBoard::operator>>(float o_Increase)
{
	o_Value += o_Increase;
	setText_O();
}

void ScoreBoard::operator<<(float x_Increase)
{
	x_Value += x_Increase;
	setText_X();
}

void ScoreBoard::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	window.draw(x_ScoreText);
	window.draw(o_ScoreText);
}

void ScoreBoard::initText()
{
	textFont.loadFromFile("Assets/ArialBold.ttf");
	x_ScoreText.setFont(textFont);
	o_ScoreText.setFont(textFont);

	sf::Color textColor = sf::Color(52u, 63u, 86u, 255u);

	x_ScoreText.setFillColor(textColor);
	o_ScoreText.setFillColor(textColor);

	x_ScoreText.setCharacterSize(30);
	o_ScoreText.setCharacterSize(30);

	std::stringstream Xstream;
	Xstream << std::fixed << std::setprecision(1) << x_Value;
	
	std::stringstream Ostream;
	Ostream << std::fixed << std::setprecision(1) << o_Value;

	x_ScoreText.setString(Xstream.str());
	o_ScoreText.setString(Ostream.str());

	x_ScoreText.setOrigin(x_ScoreText.getGlobalBounds().width / 2, x_ScoreText.getGlobalBounds().height / 2);
	o_ScoreText.setOrigin(o_ScoreText.getGlobalBounds().width / 2, o_ScoreText.getGlobalBounds().height / 2);

	x_ScoreText.setPosition({155.f,740.f});
	o_ScoreText.setPosition({250.f,740.f});
}

void ScoreBoard::setText_X()
{
	std::stringstream Xstream;
	Xstream << std::fixed << std::setprecision(1) << x_Value;

	x_ScoreText.setString(Xstream.str());
	x_ScoreText.setOrigin(x_ScoreText.getGlobalBounds().width / 2, x_ScoreText.getGlobalBounds().height / 2);
	x_ScoreText.setPosition({ 155.f,740.f });
}

void ScoreBoard::setText_O()
{
	std::stringstream Ostream;
	Ostream << std::fixed << std::setprecision(1) << o_Value;

	o_ScoreText.setString(Ostream.str());
	o_ScoreText.setOrigin(o_ScoreText.getGlobalBounds().width / 2, o_ScoreText.getGlobalBounds().height / 2);
	o_ScoreText.setPosition({ 250.f,740.f });
}