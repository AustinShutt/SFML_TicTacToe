#pragma once
#include "Definitions.h"
#include "EventHandler.h"
#include "Utility.h"
#include <iostream>

class Player : public EventHandler 
{
public:
	//Initializes local reference to board and which piece the player places on the board
	Player(BoardArray& board, char piece) : board(board), piece(piece), readyPass(false) {}

	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0; //Pure Virtual function making Player abstract class
	virtual void update() {}; //Virtual function to be overridden by inherited classes
	bool turnFinished() { return readyPass; } //Returns boolean flag signaling end of turn
	void resetPlayer() { readyPass = false; } //Returns boolean flag to initial state
	char getPlayerPiece() { return piece; } //Returns the piece that the current player places on the board during their turn

protected:
	BoardArray& board; //Reference to gameboard
	char piece; //Piece that the current character places on the board during their turn
	bool readyPass; //Boolean flag to signal when this player's turn is finished
};

class Human_Player : public Player
{
public:
	Human_Player(BoardArray& board, char piece) : Player(board, piece) {}
	void addEventHandler(sf::RenderWindow& window, sf::Event event); //Awaits human input to make a move on grid
};

class AI_Player : public Player
{

public:
	AI_Player(BoardArray& board, char piece) : Player(board, piece) {};
	
	void addEventHandler(sf::RenderWindow& window, sf::Event event) {}; //No human input with AI_Player
	void update(); //Makes move for AI Player utilizing minimax algorithm
	
private:
	sf::Vector2i minimax(); //algorithm utilized to make optimal move for AI opponent, returns that move
	int maxSearch(); //Searches board for maximum value state
	int minSearch(); //Searches board for minimum value state
};

