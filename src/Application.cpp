#include <chrono>
#include <SFML/Window/Event.hpp>
#include "Application.h"

using Clock = std::chrono::steady_clock;

Application::Application()
    : window{sf::VideoMode(1024, 768), "Tetris clone", sf::Style::Titlebar | sf::Style::Close},
      game{window} {
}

void Application::start() {
  auto start = Clock::now();
  std::chrono::nanoseconds accumulator{0};
  std::chrono::nanoseconds timestep{16666667};  // 60 updates per second

  while (window.isOpen()) {
    auto end = Clock::now();
    auto dt = end - start;
    start = end;
    accumulator += dt;

    while (accumulator >= timestep) {
      accumulator -= timestep;
      game.processInput();
      game.update();
    }

    game.render();
  }
}
