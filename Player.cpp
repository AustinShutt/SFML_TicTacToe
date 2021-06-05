#include "Player.h"

void Human_Player::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
	{
		sf::Vector2i worldPos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePos = window.mapPixelToCoords(worldPos);

		if (mousePos.y > 700.f || mousePos.y < 100.f) { return; }

		int row = (mousePos.y - 100.f) / 200.f;
		int column = mousePos.x / 200.f;

		if (board[row][column] != '-') { std::cout << "Not valid Move\n"; return; }

		board[row][column] = piece; //Sets place to either 'x' or 'o' depending on what was passed in to constructor

		std::cout << "Clicked on R:" << row << " C:" << column << std::endl;
	}
}
