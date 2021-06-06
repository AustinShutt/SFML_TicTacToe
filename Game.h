#pragma once
#include "Definitions.h"
#include "Background.h"
#include "Buttons.h"
#include "MarkerDisplay.h"
#include "Player.h"

class Game
{
	sf::RenderWindow& window;
	Background background;
	MenuButton menuButton;
	ResetButton resetButton;
	Human_Player human;
	Human_Player human2;
	Player* currentPlayer;
	
	BoardArray board = {{{ '-','-','-' },
						 { '-','-','-' },
						 { '-','-','-' }}};
	
	MarkerDisplay markerDisplay;
	bool vsComputer;
	bool isPlaying;
	bool inEndGameState;

public:
	Game(sf::RenderWindow& window, bool vsComputer);
	void Run();

private:
	void HandleEvents();
	void Update();
	void Render();

	//Helper Functions
private:
	void CheckVictoryConditions();
	void CheckTieGame();
	void SwitchCurrentPlayer();
	void ResetGame();
	void RandomizeFirstTurn();

};

