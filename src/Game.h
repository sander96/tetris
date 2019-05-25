#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Playfield.h"
#include "RandomBag.h"
#include "GameEvent.h"

class Game {
public:
  explicit Game(sf::RenderWindow& window);

  void update();

  void render();

private:
  sf::RenderWindow& window;
  Playfield playfield;
  RandomBag randomBag;

  GameEvent gameEvent = GameEvent::NONE;
};

#endif
