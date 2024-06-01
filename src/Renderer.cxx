#include "Renderer.hxx"

using namespace sf;

namespace my {
Renderer::Renderer() :
  window{ { 16u * 32, 16u * 32 }, "New Adventure"/*, Style::Titlebar | Style::Close*/ },
  spriteLoader{}
{
  window.setFramerateLimit(20);
  window.setKeyRepeatEnabled(false);
}

void Renderer::render() {
  window.clear();
  for (const auto& sprite : spriteLoader.sprites) {
    window.draw(sprite);
  }
  window.display();
}
} // namespace my
