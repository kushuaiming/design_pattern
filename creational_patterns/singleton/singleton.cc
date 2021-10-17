#include <iostream>

#include "singleton.h"

MazeFactory* MazeFactory::_instance = 0;

MazeFactory* MazeFactory::Instance() {
  if (_instance == 0) {
    _instance = new MazeFactory;
  }
  return _instance;
}

int main(int argc, char* argv[]) {
  std::cout << "start programming." << std::endl;
  return 0;
}
