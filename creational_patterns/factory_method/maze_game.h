#ifndef MAZE_GAME_H_
#define MAZE_GAME_H_

#include "map_site.h"

class MazeGame {
 public:
  MazeGame() = default;

  Maze* CreateMaze();

  // factory methdos
  virtual Maze* MakeMaze() const { return new Maze; }
  virtual Wall* MakeWall() const { return new Wall; }
  virtual Room* MakeRoom(int n) const { return new Room(n); }
  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

class BombedMazeGame : public MazeGame {
 public:
  BombedMazeGame() = default;

  virtual Wall* MakeWall() const { return new BombedWall; }
  virtual Room* MakeRoom(int n) const { return new RoomWithABomb(n); }
};

class EnchantedMazeGame : public MazeGame {
 public:
  EnchantedMazeGame() = default;

  virtual Room* MakeRoom(int n) const {
    return new EnchantedRoom(n, CastSpell());
  }
  virtual Door* MakeDoor(Room* r1, Room* r2) const {
    return new DoorNeedingSpell(r1, r2);
  }

 protected:
  Spell* CastSpell() const { return nullptr; }
};

#endif  // MAZE_GAME_H_