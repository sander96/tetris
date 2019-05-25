#ifndef TETRIS_RANDOMBAG_H
#define TETRIS_RANDOMBAG_H

#include <vector>
#include <random>
#include "BlockType.h"

class RandomBag {
public:
  BlockType next();

private:
  std::vector<BlockType> blocks;
  std::default_random_engine randomEngine;
};

#endif

