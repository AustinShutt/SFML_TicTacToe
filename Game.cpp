#include "Game.h"

Game::Game(sf::RenderWindow& window, bool vsComputer)
	:window(window), vsComputer(vsComputer)
{
	isPlaying = true;
}

void Game::Run()
{
	while (isPlaying)
	{
		HandleEvents();
		Update();
		Render();
	}
}

void Game::HandleEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		menuButton.addEventHandler(window, event);
		resetButton.addEventHandler(window, event);
		
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2i windowPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(windowPos);

				
				
				if (menuButton.getGlobalBounds().contains(mousePos))
				{
					isPlaying = false;
				}

				if (resetButton.getGlobalBounds().contains(mousePos))
				{
					std::cout << "Reset Game\n";
				}
			}
		}
	}
}

void Game::Update()
{

}

void Game::Render()
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(menuButton);
	window.draw(resetButton);
	//window.draw(displayGrid);

	window.display();
}

