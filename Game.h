#pragma once
#include "Definitions.h"
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow& window;
	bool vsComputer;
	bool isPlaying;


public:
	Game(sf::RenderWindow& window, bool vsComputer);
	void Run();

private:
	void HandleEvents();
	void Update();
	void Render();

};

