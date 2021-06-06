#include "Game.h"

Game::Game(sf::RenderWindow& window, bool vsComputer)
	:window(window), vsComputer(vsComputer), markerDisplay(board), human(board, 'x'), human2(board,'o')
{
	isPlaying = true;
	RandomizeFirstTurn();
}

void Game::Run()
{
	while (isPlaying)
	{
		HandleEvents();
		Update();
		Render();
	}
}

void Game::HandleEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		menuButton.addEventHandler(window, event);
		resetButton.addEventHandler(window, event);
		currentPlayer->addEventHandler(window, event);
		
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2i windowPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(windowPos);

				if (menuButton.isWithin(mousePos))
				{
					isPlaying = false;
				}

				if (resetButton.isWithin(mousePos))
				{
					ResetGame();
				}
			}
		}
	}
}

void Game::Update()
{
	if (currentPlayer->turnFinished() && !inEndGameState)
	{
		currentPlayer->resetPlayer();
		markerDisplay.updateBoard();
		CheckVictoryConditions();
		CheckTieGame();
		SwitchCurrentPlayer();
	}
}

void Game::Render()
{
	window.clear(sf::Color::Black);

	window.draw(background);
	window.draw(menuButton);
	window.draw(resetButton);
	window.draw(markerDisplay);

	window.display();
}

void Game::SwitchCurrentPlayer()
{
	if (currentPlayer == &human) { currentPlayer = &human2; }
	else { currentPlayer = &human; }
}

void Game::CheckVictoryConditions()
{

	if (inEndGameState) { return; }

	//Check Diagonals
	if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		std::cout << "Winner on Diagonal\n";
		inEndGameState = true;
	}
	else if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		std::cout << "Winner on other Diagonal\n";
		inEndGameState = true;
	}

	//Check Rows
	for (size_t i = 0; i < board.size(); ++i)
	{
		if (board[i][0] == '-') { continue; }
		
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			std::cout << "Winner on row: " << i << std::endl;
			inEndGameState = true;
			return;
		}
	}

	//Check Columns
	for (size_t i = 0; i < board[0].size(); ++i)
	{
		if (board[0][i] == '-') { continue; }

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			std::cout << "Winner on column: " << i << std::endl;
			inEndGameState = true;
			return;
		}
	}

	
}

void Game::CheckTieGame()
{
	if (inEndGameState) { return; }

	for (size_t i = 0; i < board.size(); ++i)
	{
		for (size_t j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] != '-') { return; }
		}
	}

	inEndGameState = true;
	std::cout << "THERE IS A TIE GAME\n";
}

void Game::ResetGame()
{
	board = {{{ '-','-','-' },
			  { '-','-','-' },
			  { '-','-','-' }}};

	
	inEndGameState = false;
	markerDisplay.updateBoard();
	RandomizeFirstTurn();
	
	std::cout << "Game has been Reset\n";
}

void Game::RandomizeFirstTurn()
{
	char rand_num = rand() % 2;

	if (rand_num == 0)
	{
		currentPlayer = &human;
		return;
	}

	currentPlayer = &human2;
}

