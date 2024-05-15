#include "Renderer.hxx"

namespace my {
  Renderer::Renderer() :
    spriteLoader{},
    window{ { 16u * 32, 16u * 32 }, "New Adventure"/*, sf::Style::Titlebar | sf::Style::Close*/ }
  {
    window.setFramerateLimit(20);
  }

  void Renderer::render() {
    window.clear();
    for (const auto& sprite : spriteLoader.sprites) {
      window.draw(sprite);
    }
    window.display();
  }
}
