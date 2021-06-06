#pragma once
#include<SFML/Graphics.hpp>
#include "Game.h"

class Application
{
	sf::RenderWindow window;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	VersusComputerButton vsComButton;
	VersusPlayerButton vsPlayButton;
	ExitButton exitButton;
	
public:
	Application(); //Owns the renderwindow and acts as a fallback point to reset the game
	void Run(); //public method to run the game from the main function

private:
	void HandleEvents(); //Handles SFML Events
	void Update(); //Updates Any Assets
	void Render(); //Draws Assets to screen
};

