#include "bridge.h"

void View::DrawOn(Window* window_ptr) {
  return;
}

void Window::DrawContents() {}
void Window::Open() {}
void Window::Close() {}
void Window::Iconify() {}
void Window::Deiconify() {}
void Window::SetOrigin(const Point& at) {}
void Window::SetExtent(const Point& extent) {}
void Window::Raise() {}
void Window::Lower() {}
void Window::DrawLine(const Point&, const Point&) {}
void Window::DrawRect(const Point&, const Point&) {}
void Window::DrawPolygon(const Point[], int n) {}
void Window::DrawText(const char*, const Point&) {}

void ApplicationWindow::DrawContents() {
  GetView()->DrawOn(this);
}

void IconWindow::DrawContents() {
  WindowImp* imp = GetWindowImp();
  if (imp != 0) {
    imp->DeviceBitmap(bitmapName_, 0.0, 0.0);
  }
}

int main(int argc, char* argv[]) {
  return 0;
}
