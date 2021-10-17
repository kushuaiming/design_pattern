#include "builder.h"

StandarMazeBuilder::StandarMazeBuilder () {
  _currentMaze = new Maze;
}

Maze* StandarMazeBuilder::GetMaze () {
  return _currentMaze;
}

void StandarMazeBuilder::BuildRoom(int n) {
  if (!_currentMaze->RoomNo(n)) {
    Room* room = new Room(n);
    _currentMaze->AddRoom(room);

    room->SetSide(North, new Wall);
    room->SetSide(East, new Wall);
    room->SetSide(South, new Wall);
    room->SetSide(West, new Wall);
  }
}

void StandarMazeBuilder::BuildDoor (int n1, int n2) {
  Room* r1 = _currentMaze->RoomNo(n1);
  Room* r2 = _currentMaze->RoomNo(n2);
  Door* d = new Door(r1, r2);

  r1->SetSide(CommanWall(r1, r2), d);
  r2->SetSide(CommanWall(r1, r2), d);
}