#include <exception>
#include <iostream>

#include "GameEngine.hxx"

int main(int, char**) {
  try {
    my::GameEngine game{};
    game.loop();
  }
  catch (std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
}
