#include "object_adapter.h"

TextShape::TextShape(TextView* t) {
  text_ = t;
}

void TextShape::BoundingBox(Point& bottomLeft, Point& topRight) const {
  Coord bottom, left, width, height;

  text_->GetOrigin(bottom, left);
  text_->GetExtent(width, height);

  bottomLeft = Point(bottom, left);
  topRight = Point(bottom + height, left + width);
}

Manipulator* TextShape::CreateManipulator () const {
  return new TextManipulator;
}

bool TextShape::IsEmpty () const {
  return text_->IsEmpty();
}
