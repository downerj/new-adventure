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

class Renderer {
public:
  Renderer() {
    // TODO: Add a Camera class that handles the sf::View.
    // sf::View view{};
    // view.setCenter(0.f, 0.f);
    // view.zoom(.5f);
    // window.setView(view);
    window.setFramerateLimit(20);
  }

  void render() {
    window.clear();
    for (const auto& sprite : spriteLoader.sprites) {
      window.draw(sprite);
    }
    window.display();
  }

  SpriteLoader spriteLoader{};
  sf::RenderWindow window{ { 16u * 32, 16u * 32 }, "New Adventure"/*, sf::Style::Titlebar | sf::Style::Close*/ };
};

class GameEngine {
public:
  GameEngine() {}

  void loop() {
    while (renderer.window.isOpen()) {
      sf::Event event{};
      while (renderer.window.pollEvent(event)) {
        const bool isCtrlPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) };
        const bool isAltPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) };
        const bool isWPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::W) };
        const bool isQPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::Q) };
        const bool isF4Pressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::F4) };

        if ((isCtrlPressed && (isWPressed || isQPressed)) || (isAltPressed && isF4Pressed)) {
          renderer.window.close();
          break;
        }
        if (event.type == sf::Event::Closed) {
          renderer.window.close();
          break;
        }
        else if (event.type == sf::Event::Resized) {
          // sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
          // window.setView(sf::View(visibleArea));
        }
      }
      renderer.render();
    }
  }

private:
  Renderer renderer{};
};

int main(int, char**) {
  try {
    GameEngine game{};
    game.loop();
  }
  catch (std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
}
