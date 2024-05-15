#include "Renderer.hxx"

namespace my {
  Renderer::Renderer() :
    window{ { 16u * 32, 16u * 32 }, "New Adventure"/*, sf::Style::Titlebar | sf::Style::Close*/ },
    spriteLoader{}
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
