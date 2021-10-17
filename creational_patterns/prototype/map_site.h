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

  virtual Room* Clone() const;
  virtual void Enter() {}

 private:
  MapSite* _sides[4];
  int _roomNumber;
};

class Spell : public MapSite {
 public:
  Spell() {}
};

class EnchantedRoom : public Room {
 public:
  EnchantedRoom(int roomNo, Spell* spell) : Room(roomNo), _spell(spell) {}

 private:
  Spell* _spell;
};

class RoomWithABomb : public Room {
 public:
  RoomWithABomb(int roomNo) : Room(roomNo) {}
};

class Wall : public MapSite {
 public:
  Wall() {}

  virtual Wall* Clone() const;

  virtual void Enter() {}
};

class BombedWall : public Wall {
 public:
  BombedWall() {}
  BombedWall(const BombedWall&);

  virtual Wall* Clone() const;
  bool HasBomb();
 private:
  bool _bomb;
};

class Door : public MapSite {
 public:
  Door(Room* r1 = 0, Room* r2 = 0) {}
  Door(const Door&);

  virtual void Initialize(Room*, Room*);
  virtual Door* Clone() const;
  virtual void Enter() {}
  Room* OtherSideFrom(Room*) { return nullptr; }

 private:
  Room* _room1;
  Room* _room2;
  bool _isOpen;
};

class DoorNeedingSpell : public Door {
 public:
  DoorNeedingSpell(Room* r1 = 0, Room* r2 = 0) : Door(r1, r2) {}
};

class Maze {
 public:
  Maze(){};

  virtual Maze* Clone() const;
  void AddRoom(Room*) {}
  Room* RoomNo(int) const { return nullptr; }

 private:
  // ...
};

#endif  // MAP_SITE_H_