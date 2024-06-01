#include <exception>
#include <iostream>

#include "GameEngine.hxx"

using namespace std;

int main(int, char**) {
  try {
    my::GameEngine game{};
    game.loop();
  } catch (exception& ex) {
    cerr << ex.what() << endl;
  }
}
