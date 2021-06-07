#include "Game.h"

Game::Game(sf::RenderWindow& window, bool vsComputer)
	:window(window), board({{{ '-','-','-' }, { '-','-','-' }, { '-','-','-' }}}), markerDisplay(board) //initializer list 
{
	X_Player = std::make_shared<Human_Player>(board, 'x'); //Initializes player1 ptr
	
	if (vsComputer) { O_Player = std::make_shared<AI_Player>(board, 'o'); } //Initializes player2 ptr
	else { O_Player = std::make_shared<Human_Player>(board, 'o'); } //Sets AI player if AI, HumanPlayer if Human

	playState = PlayState::PLAYING; //Initializes playstate enum
	RandomizeFirstTurn(); //Randomly determines who has the first turn
}

void Game::Run()
{
	//Main game loop
	while (playState != PlayState::EXITING)
	{
		HandleEvents(); //Handles Input and SFML events
		Update(); //Updates necessary objects
		Render(); //Outputs drawn entities to the window for display
	}
}

void Game::HandleEvents()
{
	sf::Event event; //Instantiates sfml event to be polled by window

	while (window.pollEvent(event))
	{
		menuButton.addEventHandler(window, event); //Handles events for window button
		resetButton.addEventHandler(window, event); //Handles events for reset button
		
		if (event.type == sf::Event::Closed) //Closes SFML window if X is pressed on window
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2i windowPos = sf::Mouse::getPosition(window); //Finds mouseposition relative to window
				sf::Vector2f mousePos = window.mapPixelToCoords(windowPos); //Converts to sf::Vector2f based on window mouse pos

				if (menuButton.contains(mousePos)) //Checks if menubutton is pressed with left click
				{
					playState = PlayState::EXITING;
					return;
				}
				if (resetButton.contains(mousePos)) //Checks if resetButton is pressed with left click
				{
					ResetGame();
				}
			}
		}

		if (playState == PlayState::PAUSED) { continue; } //Does not allow pieces to be placed if current game has ended

		currentPlayer->addEventHandler(window, event); //Handles events for currentPlayer
	}
}

void Game::Update()
{
	if (playState != PlayState::PLAYING) { return; }

	currentPlayer->update(); 
	
	if (currentPlayer->turnFinished() == false) { return; }
	//If currentplayer has taken their turn, the board is updated,
	//Victory and TieGame states of the board are checked
	//Turn is switched to the other player
	currentPlayer->resetPlayer();
	markerDisplay.updateBoard();
	CheckVictoryConditions();
	CheckTieGame();
	SwitchCurrentPlayer();
	
}

void Game::Render()
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(menuButton);
	window.draw(resetButton);
	window.draw(markerDisplay);
	window.draw(scoreBoard);

	window.display();
}

void Game::SwitchCurrentPlayer()
{
	if (currentPlayer == X_Player) { currentPlayer = O_Player; }
	else { currentPlayer = X_Player; }
}

void Game::CheckVictoryConditions()
{
	if (playState == PlayState::PAUSED) { return; }

	if (Utility::checkWin(board, currentPlayer->getPlayerPiece()))
	{
		AwardWinnerPoints();
		playState = PlayState::PAUSED;
	}
}

void Game::CheckTieGame()
{
	if (playState == PlayState::PAUSED) { return; }

	if (Utility::checkTie(board))
	{
		playState = PlayState::PAUSED;
		AwardTiePoints();
	}
}

void Game::ResetGame()
{
	//Sets board back to initial blank values
	board = {{{ '-','-','-' },
			  { '-','-','-' },
			  { '-','-','-' }}};

	
	playState = PlayState::PLAYING;
	markerDisplay.updateBoard();
	RandomizeFirstTurn();
}

void Game::RandomizeFirstTurn()
{
	char rand_num = rand() % 2;

	if (rand_num == 0)
	{
		currentPlayer = X_Player;
		return;
	}

	currentPlayer = O_Player;
}

void Game::AwardWinnerPoints()
{
	if (currentPlayer == X_Player)
		scoreBoard << 1.0f; //Uses operator overload to award X_player points on scoreboard
	else
		scoreBoard >> 1.0f; //Uses operator overload to award O_Player points on scoreboard
}

void Game::AwardTiePoints()
{
	scoreBoard >> 0.5f; //Uses operator Overload to award X points
	scoreBoard << 0.5f; //Uses operator overload to award O points
}
