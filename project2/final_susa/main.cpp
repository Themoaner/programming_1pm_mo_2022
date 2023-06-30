#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Game.h"

int main() {
    mt::Game game;
    game.SetResolution(1366, 768);
    game.SetCaption("Test game");
    game.Setup();
    game.Run();

    return 0;

}
