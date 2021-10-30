#include "common.h"
class View {
 public:
  void DrawOn(Window* window_ptr);
};

class WindowImp {
 public:
  virtual void ImpTop() = 0;
  virtual void ImpBottom() = 0;
  virtual void ImpSetExtent(const Point&) = 0;
  virtual void ImpSetOrigin(const Point&) = 0;

  virtual void DeviceRect(Coord, Coord, Coord, Coord) = 0;
  virtual void DeviceText(const char*, Coord, Coord) = 0;
  virtual void DeviceBitmap(const char*, Coord, Coord) = 0;

  // ...
 protected:
  WindowImp();
};

class XWindowImp : public WindowImp {
 public:
  XWindowImp();
  void DeviceRect(Coord, Coord, Coord, Coord) override;
};

class PMWindwoImp : public WindowImp {
 public:
  PMWindwoImp();
  void DeviceRect(Coord, Coord, Coord, Coord) override;
};

class Window {
 public:
  Window(View* contents);

  virtual void DrawContents();

  virtual void Open();
  virtual void Close();
  virtual void Iconify();
  virtual void Deiconify();

  virtual void SetOrigin(const Point& at);
  virtual void SetExtent(const Point& extent);
  virtual void Raise();
  virtual void Lower();

  virtual void DrawLine(const Point&, const Point&);
  virtual void DrawRect(const Point&, const Point&);
  virtual void DrawPolygon(const Point[], int n);
  virtual void DrawText(const char*, const Point&);

 protected:
  WindowImp* GetWindowImp() { return imp_; }
  View* GetView() { return contents_; }

 private:
  WindowImp* imp_;
  View* contents_;
};

class ApplicationWindow : public Window {
 public:
  // ...
  void DrawContents() override;
};

class IconWindow : public Window {
 public:
  // ...
  void DrawContents() override;
 private:
  const char* bitmapName_;
};