#include "class_adapter.h"

void TextShape::BoundingBox(Point& bottomLeft, Point& topRight) const {
  Coord bottom, left, width, height;

  GetOrigin(bottom, left);
  GetExtent(width, height);

  bottomLeft = Point(bottom, left);
  topRight = Point(bottom + height, left + width);
}

Manipulator* TextShape::CreateManipulator() const {
  return new TextManipulator;
}

bool TextShape::IsEmpty() const { return TextView::IsEmpty(); }

int main(int argc, char* argv[]) { return 0; }
