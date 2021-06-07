#include "Game.h"

Game::Game(sf::RenderWindow& window, bool vsComputer)
	:window(window), board({{{ '-','-','-' }, { '-','-','-' }, { '-','-','-' }}}), markerDisplay(board)
{
	X_Player = std::make_shared<Human_Player>(board, 'x'); //Initializes player 1 ptr
	
	if (vsComputer) { O_Player = std::make_shared<AI_Player>(board, 'o'); } //Initializes player 2 ptr
	else { O_Player = std::make_shared<Human_Player>(board, 'o'); }

	playState = PlayState::PLAYING;
	RandomizeFirstTurn(); //Randomly determines who has the first turn
}

void Game::Run()
{
	//Main game loop
	while (playState != PlayState::EXITING)
	{
		HandleEvents(); //
		Update(); //
		Render(); //
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
				sf::Vector2i windowPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(windowPos);

				if (menuButton.isWithin(mousePos)) //Checks if menubutton is pressed
				{
					playState = PlayState::EXITING;
					return;
				}
				if (resetButton.isWithin(mousePos)) //
				{
					ResetGame();
				}
			}
		}

		if (playState == PlayState::PAUSED) { continue; }

		currentPlayer->addEventHandler(window, event); //Handles events for currentPlayer
	}
}

void Game::Update()
{
	if (currentPlayer->turnFinished() && playState == PlayState::PLAYING)
	{
		currentPlayer->resetPlayer();
		markerDisplay.updateBoard();
		CheckVictoryConditions();
		CheckTieGame();
		SwitchCurrentPlayer();
	}

	if (playState == PlayState::PLAYING)
	{
		currentPlayer->update();
	}
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

	//Check Diagonals
	if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		playState = PlayState::PAUSED;
		AwardWinnerPoints();
	}
	else if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		playState = PlayState::PAUSED;
		AwardWinnerPoints();
	}

	//Check Rows
	for (size_t i = 0; i < board.size(); ++i)
	{
		if (board[i][0] == '-') { continue; }
		
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			playState = PlayState::PAUSED;
			AwardWinnerPoints();
			return;
		}
	}

	//Check Columns
	for (size_t i = 0; i < board[0].size(); ++i)
	{
		if (board[0][i] == '-') { continue; }

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			playState = PlayState::PAUSED;
			AwardWinnerPoints();
			return;
		}
	}
}

void Game::CheckTieGame()
{
	if (playState == PlayState::PAUSED) { return; }

	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == '-') { return; }
		}
	}

	playState = PlayState::PAUSED;
	AwardTiePoints();
}

void Game::ResetGame()
{
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
