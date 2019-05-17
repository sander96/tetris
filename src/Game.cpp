#include "Game.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window) {
}

void Game::processInput() {
  sf::Event event{};
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void Game::update() {

}

void Game::render() {
  window.clear();

  sf::CircleShape shape(100.0f);
  shape.setFillColor(sf::Color::Green);
  window.draw(shape);

  window.display();
}
