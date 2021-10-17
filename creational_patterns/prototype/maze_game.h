#ifndef MAZE_GAME_H_
#define MAZE_GAME_H_

#include "map_site.h"
#include "prototype.h"

class MazeGame {
 public:
  MazeGame() = default;

  // abstract factory
  Maze* CreateMaze(MazeFactory& factory);
};

#endif  // MAZE_GAME_H_