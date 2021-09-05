#include <SFML/Graphics.hpp>
#include "Application.h"
#include <time.h>

int main()
{
    std::srand(time(NULL)); //Initializes psuedo randomness for who gets first turn each game
    
    Application app;
    app.Run();

    return 0;
}