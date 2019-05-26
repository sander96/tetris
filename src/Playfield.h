#ifndef TETRIS_PLAYFIELD_H
#define TETRIS_PLAYFIELD_H

#include <array>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BlockType.h"
#include "Piece.h"
#include "RandomBag.h"

class Playfield {
public:
  explicit Playfield(sf::RenderWindow& window);

  void update();

  void render();

private:
  void clearAll();

  void clearFullLines();

  bool isGameOver();

  sf::Color getBlockColor(BlockType type);

  sf::RenderWindow& window;
  std::array<std::array<BlockType, 22>, 10> field;
  std::array<std::array<BlockType, 22>, 10> fallenPiecesField;
  RandomBag randomBag;

  std::unique_ptr<Piece> currentPiece;
};

#endif
