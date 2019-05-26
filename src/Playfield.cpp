#include <SFML/Graphics/RectangleShape.hpp>
#include "Playfield.h"

Playfield::Playfield(sf::RenderWindow& window)
    : window{window},
      field{},
      fallenPiecesField{},
      randomBag{} {

  currentPiece = std::unique_ptr<Piece>(new Piece(window, randomBag.next()));

  for (int i = 0; i < fallenPiecesField.size(); ++i) {
    for (int j = 0; j < fallenPiecesField[i].size(); ++j) {
      fallenPiecesField[i][j] = BlockType::NONE;
    }
  }
}

void Playfield::update() {
  field = fallenPiecesField;

  if (currentPiece->update(field)) {
    fallenPiecesField = field;
    currentPiece = std::unique_ptr<Piece>(new Piece(window, randomBag.next()));
    clearFullLines();
  }
}

void Playfield::render() {
  sf::RectangleShape block{{24, 24}};
  for (unsigned i = 0; i < field.size(); ++i) {
    for (unsigned j = 0; j < field[i].size(); ++j) {
      block.setPosition(i * 24, j * 24);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::Black);

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
    return {255, 140, 0}; // orange
  }
  return sf::Color::White;
}

void Playfield::clearFullLines() {
  for (unsigned j = field.size() - 1; j >= 0; --j) {
    bool fullLine = true;
    for (int i = 0 ; i < 10; ++i) {
      fullLine &= field[i][j] != BlockType::NONE;
    }

    if (fullLine) {
      fullLine = true;
    }
  }
}
