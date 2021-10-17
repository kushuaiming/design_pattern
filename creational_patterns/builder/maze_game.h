#ifndef MAZE_GAME_H_
#define MAZE_GAME_H_

#include "builder.h"
#include "map_site.h"

class MazeGame {
 public:
  MazeGame() = default;
  Maze* CreateMaze(MazeBuilder& builder);
  Maze* CreateComplexMaze(MazeBuilder& builder);
};

#endif  // MAZE_GAME_H_