#pragma once
#include "Definitions.h"
#include "EventHandler.h"

class Player : public EventHandler 
{
public:
	virtual void makeMove() = 0; //Pure virtual function makes class abstract
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) {};
	virtual void update() {};
protected:
	BoardArray& board;
};

class Human_Player : public Player
{
public:
	Human_Player(BoardArray& board);

	void makeMove();
	void addEventHandler(sf::RenderWindow& window, sf::Event event);
	void update();
};

class AI_Player : public Player
{
public:
	AI_Player(BoardArray& board);

	void makeMove();
	void update();
};

