#include "map_site.h"

class MazeFactory {
 public:
  MazeFactory() = default;
  virtual Maze* MakeMaze() const { return new Maze; }
  virtual Wall* MakeWall() const { return new Wall; }
  virtual Room* MakeRoom(int n) const { return new Room(n); }
  virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

class MazePrototypeFactory : public MazeFactory {
 public:
  MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

  virtual Maze* MakeMaze() const;
  virtual Wall* MakeWall() const;
  virtual Room* MakeRoom(int) const;
  virtual Door* MakeDoor(Room*, Room*) const;

 private:
  Maze* _prototypeMaze;
  Room* _prototypeRoom;
  Wall* _prototypeWall;
  Door* _prototypeDoor;
};

class EnchantedMazeFactory : public MazeFactory {
 public:
  EnchantedMazeFactory();

  virtual Room* MakeRoom(int n) const {
    return new EnchantedRoom(n, CastSpell());
  }
  virtual Door* MakeDoor(Room* r1, Room* r2) const {
    return new DoorNeedingSpell(r1, r2);
  }

 protected:
  Spell* CastSpell() const {return nullptr;}
};

class BombedMazeFactory : public MazeFactory {
 public:
  Wall* MakeWall() const {
    return new BombedWall;
  }

  Room* MakeRoom(int n) const {
    return new RoomWithABomb(n);
  }
};
