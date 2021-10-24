#include "common.h"

class TextShape : public Shape {
 public:
  TextShape(TextView*);

  void BoundingBox(Point& bottomLeft, Point& topRight) const override;
  Manipulator* CreateManipulator() const override;

  bool IsEmpty() const;

 private:
  TextView* text_;
};
