#include <iostream>

#include "maze_game.h"

Maze* MazeGame::CreateMaze(MazeBuilder& builder) {
  builder.BuildMaze();

  builder.BuildRoom(1);
  builder.BuildRoom(2);
  builder.BuildDoor(1, 2);

  return builder.GetMaze();
}

Maze* MazeGame::CreateComplexMaze(MazeBuilder& builder) {
  builder.BuildRoom(1);
  // ...
  builder.BuildRoom(1001);
  return builder.GetMaze();
}

int main(int argc, char* argv[]) {
  std::cout << "start programming." << std::endl;
  Maze* maze;
  MazeGame game;
  StandarMazeBuilder builder;

  game.CreateMaze(builder);
  maze = builder.GetMaze();
  return 0;
}
