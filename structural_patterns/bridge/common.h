class Window;

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

