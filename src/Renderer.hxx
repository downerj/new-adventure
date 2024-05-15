#ifndef RENDERER_HXX
#define RENDERER_HXX

#include <SFML/Window.hpp>

#include "SpriteLoader.hxx"

class Renderer {
public:
  Renderer();
  void render();
  SpriteLoader spriteLoader;
  sf::RenderWindow window;
};

#endif // RENDERER_HXX
