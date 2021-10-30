#include "common.h"

Coord Coord::operator+(const Coord& rhs) {
  return Coord(rhs.position_ + this->position_);
}
