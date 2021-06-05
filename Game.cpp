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
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::Update()
{

}

void Game::Render()
{
	window.clear(sf::Color::Black);

	window.display();
}
