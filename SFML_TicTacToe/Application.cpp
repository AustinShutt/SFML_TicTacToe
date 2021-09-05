#include "Application.h"

Application::Application()
{
	//Window height and width defined in Definitions.h
	//Creates SFML window
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Tic-Tac-Toe");
	//Loads the background texture from file location
	backgroundTexture.loadFromFile("Assets/MenuBackground.png");
	//Binds Sf:Texture for the backgroudn to sf::Sprite 
	background.setTexture(backgroundTexture);
}

void Application::Run()
{
	//Main driving loop of SFML application main menu and
	//acts as fallback point from game instance
	while (window.isOpen())
	{
		HandleEvents(); //Handles SFML Events
		Update(); //Updates any requisite classes on each frame
		Render(); //Handles  sfml draw calls each frame
	}
}

void Application::HandleEvents()
{
	sf::Event event; //Initilizes an sf::event for window to poll

	while (window.pollEvent(event))
	{
		vsComButton.addEventHandler(window, event); //Handles events as defined by the button class
		vsPlayButton.addEventHandler(window, event); //In this instance, button expands when moused over
		exitButton.addEventHandler(window, event); // And shrinks when mouse leaves boundaries

		if (event.type == sf::Event::Closed)
		{
			window.close(); //Closes the window if X in upper right corner of window is pressed
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2i worldPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(worldPos);

				if (vsComButton.contains(mousePos)) //Launches game vs computer if vsComButton is clicked
				{
					Game game(window, true);
					game.Run();
					return;
				}
				else if (vsPlayButton.contains(mousePos)) //Launches game for pvp 
				{
					Game game(window, false);
					game.Run();
					return;
				}
				else if (exitButton.contains(mousePos)) //Exits the application
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
	//Handles all drawn elements for the menu screen
	window.clear(sf::Color::Black);
	window.draw(background);
	window.draw(vsComButton);
	window.draw(vsPlayButton);
	window.draw(exitButton);
	window.display();
}
