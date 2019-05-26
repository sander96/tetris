#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Playfield.h"

class Game {
public:
  explicit Game(sf::RenderWindow& window);

  void update();

  void render();

private:
  sf::RenderWindow& window;
  Playfield playfield;
};

#endif
