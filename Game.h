#pragma once
#include "Definitions.h"
#include "Background.h"
#include "Buttons.h"
#include "MarkerDisplay.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "Utility.h"

enum class PlayState { PLAYING = 0, PAUSED, EXITING };

class Game
{
	sf::RenderWindow& window; //window reference passed from application in constructor
	Background background; //background for tic tac toe game
	MenuButton menuButton; //Menu Button exiting the game instance and returning to the menu
	ResetButton resetButton; //Resets the board to prepare for the next game
	ScoreBoard scoreBoard; //Keeps track of game store and displays it at the bottom of the screen
	
	std::shared_ptr<Player> X_Player; //Player shared ptr for player 1
	std::shared_ptr<Player> O_Player; //shared Ptr for either computer or player 2 depending on selection from main menu
	std::shared_ptr<Player> currentPlayer; //pointer that pointers to the player who's turn it is

	BoardArray board; //array<array<char,3u>,3u> for the game board
	MarkerDisplay markerDisplay; //Holds a reference to the game board and draws the board each time a move is made from a player
	PlayState playState; //Enum to control flow during particular gamestates
	

public:
	Game(sf::RenderWindow& window, bool vsComputer);
	void Run(); //Performs main game loop

private:
	void HandleEvents();
	void Update();
	void Render();

	//Helper Functions
private:
	void CheckVictoryConditions(); //Checks if victory condition occured for current player 
	void CheckTieGame();  //Checks if there are any available moves to be made
	void SwitchCurrentPlayer(); //Switches the currentplayer pointer 
	void ResetGame(); //Returns the game to the starting condition
	void RandomizeFirstTurn(); //Draws a psuedo random number to decide which player goes first for each game
	void AwardWinnerPoints(); //Awards points to the scoreboard in event of a win
	void AwardTiePoints(); //Awards 0.5 points to both players in event of a tie
};

