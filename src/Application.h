#ifndef TETRIS_APPLICATION_H
#define TETRIS_APPLICATION_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"

class Application {
public:
  Application();

  void start();

private:
  sf::RenderWindow window;
  Game game;
};


#endif
