#include <chrono>
#include "Application.h"

using namespace std::chrono;

Application::Application()
    : window{sf::VideoMode(240, 768), "Tetris clone", sf::Style::Titlebar | sf::Style::Close},
      game{window} {
}

void Application::start() {
  auto start = steady_clock::now();
  nanoseconds accumulator{0};
  nanoseconds timestep = duration_cast<nanoseconds>(duration<double>(1.0 / fps));

  while (window.isOpen()) {
    auto end = steady_clock::now();
    auto dt = end - start;
    start = end;
    accumulator += dt;

    while (accumulator >= timestep) {
      accumulator -= timestep;
      game.update();
    }

    game.render();
  }
}
