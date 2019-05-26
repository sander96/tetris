#include <SFML/Window/Event.hpp>
#include "Piece.h"
#include "Application.h"

Piece::Piece(sf::RenderWindow& window, BlockType type)
    : window{window},
      type(type) {

  if (type == BlockType::I) {
    pieceState.piece = {{false, false, false, false},
                        {true,  true,  true,  true},
                        {false, false, false, false},
                        {false, false, false, false}};
  } else if (type == BlockType::O) {
    pieceState.piece = {{true, true},
                        {true, true}};
  } else if (type == BlockType::T) {
    pieceState.piece = {{false, true,  false},
                        {true,  true,  true},
                        {false, false, false}};
  } else if (type == BlockType::S) {
    pieceState.piece = {{false, true,  true},
                        {true,  true,  false},
                        {false, false, false}};
  } else if (type == BlockType::Z) {
    pieceState.piece = {{true,  true,  false},
                        {false, true,  true},
                        {false, false, false}};
  } else if (type == BlockType::J) {
    pieceState.piece = {{true,  false, false},
                        {true,  true,  true},
                        {false, false, false}};
  } else if (type == BlockType::L) {
    pieceState.piece = {{false, false, true},
                        {true,  true,  true},
                        {false, false, false}};
  }

  pieceState.positionX = 0;
  pieceState.positionY = 0;
}

/**
 * @return true if the current piece has fallen, false otherwise.
 */
bool Piece::update(std::array<std::array<BlockType, 22>, 10>& field) {
  PieceState previousState = pieceState;
  GameEvent gameEvent = processInput();

  if (gameEvent == GameEvent::LEFT) {
    --pieceState.positionX;
  } else if (gameEvent == GameEvent::RIGHT) {
    ++pieceState.positionX;
  } else if (gameEvent == GameEvent::ROTATE_RIGHT) {
    rotate();
    rotate();
    rotate();
  } else if (gameEvent == GameEvent::ROTATE_LEFT) {
    rotate();
  } else if (gameEvent == GameEvent::DROP) {
    for (int i = 0; !hasFallen(field); ++i) {
      pieceState = previousState;
      pieceState.positionY += i;
    }
  }
  if (isCollision(field)) {
    pieceState = previousState;
  }

  if (updatesCount % 30 == 0) {

    if (hasFallen(field)) {
      for (unsigned i = 0; i < pieceState.piece.size(); ++i) {
        for (unsigned j = 0; j < pieceState.piece[i].size(); ++j) {
          if (pieceState.piece[i][j]) {
            field[i + pieceState.positionX][j + pieceState.positionY] = type;
          }
        }
      }
      return true;
    }

    ++pieceState.positionY;
  }
  ++updatesCount;

  for (unsigned i = 0; i < pieceState.piece.size(); ++i) {
    for (unsigned j = 0; j < pieceState.piece[i].size(); ++j) {
      if (pieceState.piece[i][j]) {
        field[i + pieceState.positionX][j + pieceState.positionY] = type;
      }
    }
  }

  return false;
}

bool Piece::hasFallen(const std::array<std::array<BlockType, 22>, 10>& field) {
  for (unsigned i = 0; i < pieceState.piece.size(); ++i) {
    for (unsigned j = 0; j < pieceState.piece[i].size(); ++j) {
      if (pieceState.piece[i][j]) {
        if (pieceState.positionY + j > 20) {
          return true;
        }

        if (field[pieceState.positionX + i][pieceState.positionY + j + 1] != BlockType::NONE) {
          return true;
        }
      }
    }
  }
  return false;
}

bool Piece::isCollision(const std::array<std::array<BlockType, 22>, 10>& field) {
  for (unsigned i = 0; i < pieceState.piece.size(); ++i) {
    for (unsigned j = 0; j < pieceState.piece[i].size(); ++j) {
      if (pieceState.piece[i][j] && (pieceState.positionX + i < 0 || pieceState.positionX + i >= 10 ||
                                     pieceState.positionY + j >= 22 || pieceState.positionY + j < 0 ||
                                     field[pieceState.positionX + i][pieceState.positionY + j] != BlockType::NONE)) {
        return true;
      }
    }
  }
  return false;
}

GameEvent Piece::processInput() {
  sf::Event event{};
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }

    if (event.type == sf::Event::KeyReleased) {
      if (event.key.code == sf::Keyboard::A) {
        return GameEvent::LEFT;
      } else if (event.key.code == sf::Keyboard::D) {
        return GameEvent::RIGHT;
      } else if (event.key.code == sf::Keyboard::Space) {
        return GameEvent::DROP;
      } else if (event.key.code == sf::Keyboard::Q) {
        return GameEvent::ROTATE_LEFT;
      } else if (event.key.code == sf::Keyboard::E) {
        return GameEvent::ROTATE_RIGHT;
      }
    }
  }
  return GameEvent::NONE;
}

void Piece::rotate() {
  auto state = pieceState.piece;
  for (unsigned i = 0; i < pieceState.piece.size(); ++i) {
    for (unsigned j = 0; j < pieceState.piece[i].size(); ++j) {
      state[i][j] = pieceState.piece[pieceState.piece.size() - 1 - j][i];
    }
  }
  pieceState.piece = state;
}
