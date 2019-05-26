#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Game.h"

Game::Game(sf::RenderWindow& window)
    : window(window),
      playfield{window} {
}

void Game::update() {
  playfield.update();
}

void Game::render() {
  window.clear();

  playfield.render();

  window.display();
}
