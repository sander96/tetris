#include <SFML/Graphics/RectangleShape.hpp>
#include "Playfield.h"

Playfield::Playfield(sf::RenderWindow& window)
    : window{window},
      field{},
      fallenPiecesField{} {
}

void Playfield::update(RandomBag& randomBag) {

  // TODO rename to line, row etc
  for (unsigned i = 0; i < field.size(); ++i) {
    for (unsigned j = 0; j < field[i].size(); ++j) {
      field[i][j] = fallenPiecesField[i][j];
    }
  }

  if (currentPiece == nullptr) {
    currentPiece = std::unique_ptr<Piece>(new Piece(window, randomBag.next()));
  }

  if (currentPiece != nullptr && currentPiece->update(field)) {
    fallenPiecesField = field;
    currentPiece = std::unique_ptr<Piece>(new Piece(window, randomBag.next()));
  }


}

void Playfield::render() {
  for (unsigned i = 0; i < field.size(); ++i) {
    for (unsigned j = 0; j < field[i].size(); ++j) {
      sf::RectangleShape block{{24, 24}};
      block.setPosition(i * 24, j * 24);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::Green);

      BlockType type = field[i][j];
      block.setFillColor(getBlockColor(type));

      window.draw(block);
    }
  }
}

sf::Color Playfield::getBlockColor(BlockType type) {
  if (type == BlockType::I) {
    return sf::Color::Cyan;
  } else if (type == BlockType::O) {
    return sf::Color::Yellow;
  } else if (type == BlockType::T) {
    return {128, 0, 128}; // purple
  } else if (type == BlockType::S) {
    return sf::Color::Green;
  } else if (type == BlockType::Z) {
    return sf::Color::Red;
  } else if (type == BlockType::J) {
    return sf::Color::Blue;
  } else if (type == BlockType::L) {
    return {255, 140, 0}; // ORANGE
  }
  return sf::Color::White;
}
