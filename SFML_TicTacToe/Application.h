#pragma once
#include<SFML/Graphics.hpp>
#include "Game.h"

class Application
{
	sf::RenderWindow window; //SFML Renderwindow, is owned here and passed to game each time a new game instance is created
	sf::Texture backgroundTexture; //SFML Texture that is bound to the sf::Sprite background for display on menu screen
	sf::Sprite background; //Sprite that displays the background of the main menu screen
	VersusComputerButton vsComButton; //Button for the vs Computer Option
	VersusPlayerButton vsPlayButton; //Button for the vs player option
	ExitButton exitButton; //Button to exit the game from the main menu
	
public:
	Application(); //Owns the renderwindow and acts as a fallback point to reset the game
	void Run(); //public method to run the game from the main function

private:
	void HandleEvents(); //Handles SFML Events
	void Update(); //Updates Any Assets
	void Render(); //Draws Assets to screen
};

