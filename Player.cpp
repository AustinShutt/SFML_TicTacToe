#include "Player.h"

void Human_Player::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
	{
		
		constexpr float BOARD_TOP = 100.f;
		constexpr float BOARD_BOTTOM = 700.f;
		constexpr float GRID_SIZE = 200.f;
		
		sf::Vector2i worldPos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePos = window.mapPixelToCoords(worldPos);

		if (mousePos.y > BOARD_BOTTOM || mousePos.y < BOARD_TOP) { return; }

		int row = (mousePos.y - BOARD_TOP) / GRID_SIZE;
		int column = mousePos.x / GRID_SIZE;

		if (board[row][column] != '-') { std::cout << "Not valid Move\n"; return; }

		board[row][column] = piece; //Sets place to either 'x' or 'o' depending on what was passed in to constructor
		readyPass = true;

		std::cout << "Clicked on R:" << row << " C:" << column << std::endl;
	}
}

void AI_Player::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
  
}

void AI_Player::update()
{
    sf::Vector2i move = minimax();

    board[move.x][move.y] = 'o';

    readyPass = true;
}

sf::Vector2i AI_Player::minimax()
{
    int value = INT_MAX;
    sf::Vector2i move;

    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'o';

                int best = maxSearch();

                if (best < value)
                {
                    value = best;
                    move.x = i;
                    move.y = j;
                }
                board[i][j] = '-';
            }
        }
    }

    return move;
}

bool AI_Player::checkWin(char gamePiece)
{
    for (size_t i = 0; i < board.size(); i++)
    {
        // Check horizontals
        if (board[i][0] == gamePiece && board[i][1] == gamePiece && board[i][2] == gamePiece)
            return true;

        // Check verticals
        if (board[0][i] == gamePiece && board[1][i] == gamePiece && board[2][i] == gamePiece)
            return true;
    }

    // Check diagonals
    if (board[0][0] == gamePiece && board[1][1] == gamePiece && board[2][2] == gamePiece)
        return true;

    if (board[0][2] == gamePiece && board[1][1] == gamePiece && board[2][0] == gamePiece)
        return true;

    return false;
}

bool AI_Player::checkTie()
{
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-') { return false; }
        }
    }
    return true;
}

int AI_Player::maxSearch()
{
    if (checkWin('x')) { return 10; }
    else if (checkWin('o')) { return -10; }
    else if (checkTie()) { return 0; }

    int score = std::numeric_limits<int>::min();

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'x';
                score = std::max(score, minSearch());
                board[i][j] = '-';
            }
        }
    }

    return score;
}

int AI_Player::minSearch()
{
    if (checkWin('x')) { return 10; }
    else if (checkWin('o')) { return -10; }
    else if (checkTie()) { return 0; }

    int score = std::numeric_limits<int>::max();

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'o';
                score = std::min(score, maxSearch());
                board[i][j] = '-';
            }
        }
    }

    return score;
}