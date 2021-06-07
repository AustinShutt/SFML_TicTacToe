#pragma once
#include "Definitions.h"
#include "EventHandler.h"
#include <iostream>

class Player : public EventHandler 
{
public:
	//Initializes local reference to board and which piece the player places on the board
	Player(BoardArray& board, char piece) : board(board), piece(piece) {}

	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
	virtual void update() {};
	bool turnFinished() { return readyPass; }
	void resetPlayer() { readyPass = false; }

protected:
	BoardArray& board;
	char piece = 'a';
	bool readyPass = false;
};

class Human_Player : public Player
{
public:
	Human_Player(BoardArray& board, char piece) : Player(board, piece) {}
	void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

class AI_Player : public Player
{

public:
	AI_Player(BoardArray& board, char piece) : Player(board, piece) {};
	
	void addEventHandler(sf::RenderWindow& window, sf::Event event);
	void update();
	
private:
	sf::Vector2i minimax();
	bool checkWin(char gamePiece);
	bool checkTie();
	int maxSearch();
	int minSearch();
};

