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

		if (board[row][column] != '-') { return; }

		board[row][column] = piece; //Sets place to either 'x' or 'o' depending on what was passed in to constructor
		readyPass = true;
	}
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

int AI_Player::maxSearch()
{
    if (Utility::checkWin(board,'x')) { return 10; }
    else if (Utility::checkWin(board,'o')) { return -10; }
    else if (Utility::checkTie(board)) { return 0; }

    int score = INT_MIN;

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
    if (Utility::checkWin(board,'x')) { return 10; }
    else if (Utility::checkWin(board,'o')) { return -10; }
    else if (Utility::checkTie(board)) { return 0; }

    int score = INT_MAX;

    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
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