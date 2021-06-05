#pragma once
#include "Definitions.h"
#include "Background.h"
#include "Buttons.h"

class Game
{
	sf::RenderWindow& window;
	Background background;
	MenuButton menuButton;
	ResetButton resetButton;
	

	//Xplayer
	//O_player
	//playerPtr;

	char board[3][3] = { {'-','-','-'},
						 {'-','-','-'},
						 {'-','-','-'} };
	
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

