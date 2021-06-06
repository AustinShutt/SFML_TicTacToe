#include "Application.h"

Application::Application()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Tic-Tac-Toe");
	
	backgroundTexture.loadFromFile("Assets/MenuBackground.png");
	background.setTexture(backgroundTexture);
}

void Application::Run()
{
	while (window.isOpen())
	{
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
		vsComButton.addEventHandler(window, event); //Expands the buttons when moused over
		vsPlayButton.addEventHandler(window, event);
		exitButton.addEventHandler(window, event);

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2i worldPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(worldPos);

				if (vsComButton.isWithin(mousePos))
				{
					Game game(window, true);
					game.Run();
					return;
				}
				else if (vsPlayButton.isWithin(mousePos))
				{
					Game game(window, false);
					game.Run();
					return;
				}
				else if (exitButton.isWithin(mousePos))
				{
					window.close();
				}
			}
		}
	}
}

void Application::Update()
{
}

void Application::Render()
{
	window.clear(sf::Color::Black);
	window.draw(background);
	window.draw(vsComButton);
	window.draw(vsPlayButton);
	window.draw(exitButton);
	window.display();
}
