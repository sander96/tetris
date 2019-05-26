#include "RandomBag.h"
#include <algorithm>

BlockType RandomBag::next() {
  if (blocks.empty()) {
    blocks = {BlockType::I, BlockType::O, BlockType::T, BlockType::S, BlockType::Z, BlockType::J, BlockType::L};
    std::shuffle(blocks.begin(), blocks.end(), randomEngine);
  }
  BlockType value = blocks.back();
  blocks.pop_back();
  return value;
}
