#pragma once
#include <SFML/Graphics.hpp>

class EventHandler //Fulfills Abstract Class Requirement
{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};