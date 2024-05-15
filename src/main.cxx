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
#include <tileson.hpp>

#include "GameEngine.hxx"
#include "InputHandler.hxx"
#include "SpriteLoader.hxx"
#include "Renderer.hxx"

namespace fs = std::filesystem;
using uint = unsigned int;

class SpriteLoader {
public:
  SpriteLoader() {
    map = std::move(t.parse(fs::path{"assets"} / "maps" / "map1.json"));
    if (map->getStatus() != tson::ParseStatus::OK) {
      throw std::runtime_error{ "Error loading map" };
    }

    layers.push_back(map->getLayer("Ground"));
    layers.push_back(map->getLayer("Terrain"));
    layers.push_back(map->getLayer("Objects"));
    overworldTileset = map->getTileset("overworld");
    const fs::path& imgPath{ overworldTileset->getFullImagePath() };
    if (!overworldTexture.loadFromFile(imgPath.string())) {
      throw std::runtime_error{ "Error loading tileset image" };
    }

    for (const auto& layer : layers) {
      for (const auto& [pos, tile] : layer->getTileObjects()) {
        std::ignore = pos;
        const tson::Rect rect{ tile.getDrawingRect() };
        const tson::Vector2f position{ tile.getPosition() };
        sf::Sprite sprite{};
        sprite.setTexture(overworldTexture);
        sprite.setTextureRect({ rect.x, rect.y, rect.width, rect.height });
        sprite.setPosition(position.x, position.y);
        sprites.push_back(std::move(sprite));
      }
    }
  }

  std::vector<sf::Sprite> sprites{};

private:
  tson::Tileson t{};
  std::unique_ptr<tson::Map> map;
  std::vector<tson::Layer*> layers{};
  tson::Tileset* overworldTileset;
  sf::Texture overworldTexture{};
};

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
