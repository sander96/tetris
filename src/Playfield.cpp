#include <SFML/Graphics.hpp>
#include "Playfield.h"

Playfield::Playfield(sf::RenderWindow& window)
    : window{window},
      field{},
      fallenPiecesField{},
      randomBag{} {

  currentPiece = std::unique_ptr<Piece>(new Piece(window, randomBag.next()));
  clearAll();
}

void Playfield::update() {
  field = fallenPiecesField;

  if (currentPiece->update(field)) {
    fallenPiecesField = field;
    currentPiece = std::unique_ptr<Piece>(new Piece(window, randomBag.next()));
    clearFullLines();

    if (isGameOver()) {
      clearAll();
    }
  }
}

void Playfield::render() {
  sf::RectangleShape block{{36, 36}};
  for (unsigned i = 0; i < field.size(); ++i) {
    for (unsigned j = 2; j < field[i].size(); ++j) {
      block.setPosition(i * 36, (j - 2) * 36);
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
  for (int i = 0; i <= 21; ++i) {
    bool fullLine = true;
    for (int j = 0; j < 10; ++j) {
      fullLine = fullLine && fallenPiecesField[j][i] != BlockType::NONE;
    }

    if (fullLine) {
      for (int a = i; a > 0; --a) {
        for (int b = 0; b < 10; ++b) {
          fallenPiecesField[b][a] = fallenPiecesField[b][a - 1];
        }
      }
    }
  }
}

bool Playfield::isGameOver() {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (fallenPiecesField[j][i] != BlockType::NONE) {
        return true;
      }
    }
  }
  return false;
}

void Playfield::clearAll() {
  for (auto& i : fallenPiecesField) {
    for (auto& j : i) {
      j = BlockType::NONE;
    }
  }
}
