#pragma once
#include "Definitions.h"
#include "EventHandler.h"
#include <iostream>

class Player : public EventHandler 
{
public:
	Player(BoardArray& board, char piece) : board(board), piece(piece) {}

	virtual void makeMove() = 0; //Pure virtual function makes class abstract
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) {};
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

	void makeMove() {};
	void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

class AI_Player : public Player
{
public:
	AI_Player(BoardArray& board, char piece) : Player(board, piece) {};

	void addEventHandler(sf::RenderWindow& window, sf::Event event) {};
	void makeMove() {};
	void update() {};
};

