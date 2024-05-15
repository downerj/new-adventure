#ifndef RENDERER_HXX
#define RENDERER_HXX

#include <SFML/Window.hpp>

#include "SpriteLoader.hxx"

namespace my {
class Renderer {
public:
  Renderer();
  Renderer(const Renderer&) = delete;
  Renderer(Renderer&&) noexcept = delete;
  Renderer& operator=(const Renderer&) = delete;
  Renderer& operator=(Renderer&&) = delete;
  void render();
  sf::RenderWindow window;
private:
  SpriteLoader spriteLoader;
};
} // namespace my

#endif // RENDERER_HXX
