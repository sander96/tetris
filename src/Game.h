#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

class Game {
public:
  explicit Game(sf::RenderWindow& window);

  void processInput();

  void update();

  void render();

private:
  sf::RenderWindow& window;

};

#endif
