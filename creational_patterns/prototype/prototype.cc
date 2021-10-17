#include "prototype.h"

MazePrototypeFactory::MazePrototypeFactory (Maze* m, Wall* w, Room* r, Door* d) {
  _prototypeMaze = m;
  _prototypeRoom = r;
  _prototypeWall = w;
  _prototypeDoor = d;
}

Maze* MazePrototypeFactory::MakeMaze() const {
  return _prototypeMaze->Clone();
}
Wall* MazePrototypeFactory::MakeWall() const { return new Wall; }
Room* MazePrototypeFactory::MakeRoom(int n) const { return new Room(n); }
Door* MazePrototypeFactory::MakeDoor(Room* r1, Room* r2) const {
  Door* door = _prototypeDoor->Clone();
  door->Initialize(r1, r2);
  return door;
}
