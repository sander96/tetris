#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include <deque>
#include <array>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BlockType.h"
#include "GameEvent.h"

struct PieceState{
  int positionX = 0;
  int positionY = 0;
  std::deque<std::deque<bool>> piece;
};

class Piece {
public:
  Piece(sf::RenderWindow& window, BlockType type);

  bool update(std::array<std::array<BlockType, 22>, 10>& field);

private:
  bool hasFallen(const std::array<std::array<BlockType, 22>, 10>& field);

  bool isCollision(const std::array<std::array<BlockType, 22>, 10>& field);

  void rotate();

  GameEvent processInput();


  sf::RenderWindow& window;
  BlockType type;
  unsigned updatesCount{};

  PieceState pieceState;
};

#endif
