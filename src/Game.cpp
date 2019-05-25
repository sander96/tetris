#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Game.h"

Game::Game(sf::RenderWindow& window)
    : window(window),
      playfield{window},
      randomBag{} {
}

void Game::update() {
  // read input
  int x = 1;
  bool down = true;

  // update moving piece

  playfield.update(randomBag);
  gameEvent = GameEvent::NONE;
}

void Game::render() {
  window.clear();

  playfield.render();

  window.display();
}
