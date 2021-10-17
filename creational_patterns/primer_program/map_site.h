#ifndef MAP_SITE_H_
#define MAP_SITE_H_

enum Direction { North, South, East, West };

class MapSite {
 public:
  virtual void Enter() = 0;
};

class Room : public MapSite {
 public:
  Room(int roomNo) {}

  MapSite* GetSide(Direction) const { return nullptr; }
  void SetSide(Direction, MapSite*) {}

  virtual void Enter() {}

 private:
  MapSite* _sides[4];
  int _roomNumber;
};

class Wall : public MapSite {
 public:
  Wall() {}

  virtual void Enter() {}
};

class Door : public MapSite {
 public:
  Door(Room* = 0, Room* = 0) {}

  virtual void Enter() {}
  Room* OtherSideFrom(Room*) { return nullptr; }

 private:
  Room* _room1;
  Room* _room2;
  bool _isOpen;
};

class Maze {
 public:
  Maze(){};

  void AddRoom(Room*) {}
  Room* RoomNo(int) const { return nullptr; }

 private:
  // ...
};

#endif  // MAP_SITE_H_