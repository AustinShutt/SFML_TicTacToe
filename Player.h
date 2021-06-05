#pragma once
#include "Definitions.h"
#include "EventHandler.h"
#include <iostream>

struct Move {
	int i, j;
};

class Player : public EventHandler 
{
public:
	Player(BoardArray& board, char piece) : board(board), piece(piece) {}

	virtual void makeMove() = 0; //Pure virtual function makes class abstract
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) {};
	virtual void update() {};
protected:
	BoardArray& board;
	char piece = 'a';
};

class Human_Player : public Player
{
public:
	Human_Player(BoardArray& board, char piece) : Player(board, piece) {}

	void makeMove() {};
	void addEventHandler(sf::RenderWindow& window, sf::Event event);
	
};

class AI_Player : public Player
{
public:
	AI_Player(BoardArray& board, char piece) : Player(board, piece) {};

	void makeMove() {};
	void update() {};
};

