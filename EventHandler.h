#pragma once
#include <SFML/Graphics.hpp>

class EventHandler //Fulfills Abstract Class Requirement
{
public:
    //Pure virtual function function to add event handler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    //Pure virtual function update
    virtual void update() = 0;
};