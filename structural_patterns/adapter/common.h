class Coord {
 public:
  Coord(double position = 0.0) : position_(position) {}
  Coord operator+(const Coord& rhs);

 private:
  double position_;
};

class Point {
 public:
  Point(Coord x, Coord y) : x_(x), y_(y) {}

 private:
  Coord x_;
  Coord y_;
};

class Manipulator {};

class TextManipulator : public Manipulator {
 public:
  TextManipulator() {}
};

class Shape {
 public:
  Shape();
  virtual void BoundingBox(Point& bottomLeft, Point& topRight) const {}
  virtual Manipulator* CreateManipulator() const {return nullptr;}
};

class TextView {
 public:
  TextView();
  void GetOrigin(Coord& x, Coord& y) const {}
  void GetExtent(Coord& width, Coord& height) const {}
  virtual bool IsEmpty() const { return true; }
};
