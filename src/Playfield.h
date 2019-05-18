#ifndef TETRIS_PLAYFIELD_H
#define TETRIS_PLAYFIELD_H

#include <array>
#include <SFML/Graphics/RenderWindow.hpp>
#include "TetrominoType.h"

class Playfield {
public:
  explicit Playfield(sf::RenderWindow& window);

  void render();

private:
  sf::Color getPieceColor(TetrominoType type);  // TODO maybe not the best place to put this

  sf::RenderWindow& window;
  std::array<std::array<TetrominoType, 22>, 10> field;

  // ghost piece

  // current piece

};

#endif
