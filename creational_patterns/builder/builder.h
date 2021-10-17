#include "map_site.h"

class MazeBuilder {
 public:
  virtual void BuildMaze() {}
  virtual void BuildRoom(int room) {}
  virtual void BuildDoor(int roomFrom, int roomTo) {}

  virtual Maze* GetMaze() { return 0; }

 protected:
  MazeBuilder() = default;
};

class StandarMazeBuilder : public MazeBuilder {
 public:
  StandarMazeBuilder();

  void BuildMaze() {}
  void BuildRoom(int);
  void BuildDoor(int, int);

  Maze* GetMaze();

 private:
  Direction CommanWall(Room*, Room*) { return North; }
  Maze* _currentMaze;
};
