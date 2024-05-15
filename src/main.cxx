#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>
#include <tuple>
#include <utility>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <tileson/tileson.hpp>

#include "GameEngine.hxx"
#include "InputHandler.hxx"
#include "SpriteLoader.hxx"
#include "Renderer.hxx"

int main(int, char**) {
  try {
    my::GameEngine game{};
    game.loop();
  }
  catch (std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
}
