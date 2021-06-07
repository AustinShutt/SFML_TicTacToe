#pragma once
#include "Definitions.h"

class Utility 
{
public:
	static bool checkWin(BoardArray& board, char gamePiece)
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

	static bool checkTie(BoardArray& board)
	{
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                //Exits early if there is a blank space on the board
                if (board[i][j] == '-') { return false; }
            }
        }

        //There is a tie if function does not early return
        return true;
	}
};

