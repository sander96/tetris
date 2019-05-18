#include <SFML/Graphics/RectangleShape.hpp>
#include "Playfield.h"

Playfield::Playfield(sf::RenderWindow& window)
    : window{window},
      field{} {
  field[0][0] = TetrominoType::J;
  field[0][1] = TetrominoType::J;
  field[0][2] = TetrominoType::J;
}

void Playfield::render() {
  for (unsigned i = 0; i < field.size(); ++i) {
    for (unsigned j = 2; j < field[i].size(); ++j) {
      sf::RectangleShape block{{24, 24}};
      block.setPosition(i * 24, (j - 2) * 24);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::Green);

      TetrominoType type = field[i][j];
      block.setFillColor(getPieceColor(type));

      window.draw(block);
    }
  }
}

sf::Color Playfield::getPieceColor(TetrominoType type) {
  if (type == TetrominoType::I) {
    return sf::Color::Cyan;
  } else if (type == TetrominoType::O) {
    return sf::Color::Yellow;
  } else if (type == TetrominoType::T) {
    return {128, 0, 128}; // purple
  } else if (type == TetrominoType::S) {
    return sf::Color::Green;
  } else if (type == TetrominoType::Z) {
    return sf::Color::Red;
  } else if (type == TetrominoType::J) {
    return sf::Color::Blue;
  } else if (type == TetrominoType::L) {
    return {255, 140, 0}; // yellow
  }
  return sf::Color::White;
}
