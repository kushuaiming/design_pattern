#include "common.h"

class TextShape : public Shape, private TextView {
 public:
  TextShape();

  void BoundingBox(Point& bottomLeft, Point& topRight) const override;
  Manipulator* CreateManipulator() const override;

  bool IsEmpty() const override;
};
