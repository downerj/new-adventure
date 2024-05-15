#ifndef RENDERER_HXX
#define RENDERER_HXX

#include <SFML/Window.hpp>

#include "SpriteLoader.hxx"

namespace my {
  class Renderer {
  public:
    Renderer();
    void render();
    sf::RenderWindow window;
  private:
    SpriteLoader spriteLoader;
  };
}

#endif // RENDERER_HXX
