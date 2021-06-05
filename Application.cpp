#include "Application.h"

Application::Application()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Tic-Tac-Toe");
}

void Application::Run()
{
	while (window.isOpen())
	{
		Game game(window, false); //Temporary Debug placement
		game.Run();

		HandleEvents();
		Update();
		Render();
	}
}

void Application::HandleEvents()
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

void Application::Update()
{
}

void Application::Render()
{
	window.clear(sf::Color::Black);

	window.display();
}
