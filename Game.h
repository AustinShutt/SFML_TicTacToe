#pragma once
#include "Definitions.h"
#include "Background.h"
#include "Buttons.h"
#include "MarkerDisplay.h"

class Game
{
	sf::RenderWindow& window;
	Background background;
	MenuButton menuButton;
	ResetButton resetButton;
	

	//Xplayer
	//O_player
	//playerPtr;

	BoardArray board = {{{ 'x','-','o' },
						 { 'x','o','-' },
						 { '-','-','-' }}};
	
	MarkerDisplay markerDisplay;
	bool vsComputer;
	bool isPlaying;

public:
	Game(sf::RenderWindow& window, bool vsComputer);
	void Run();

private:
	void HandleEvents();
	void Update();
	void Render();

	//Helper Functions
private:
};

