#include <cstdlib>
#include <filesystem>
#include <memory>
#include <utility>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <tileson.hpp>

namespace fs = std::filesystem;
using uint = unsigned int;

namespace my {
  struct Dimensions {
    uint width;
    uint height;
  };
}

int main(int, char**) {
  my::Dimensions winDims{16u*32u, 16u*32u};
  const sf::VideoMode winMode{winDims.width, winDims.height};
  sf::RenderWindow window{winMode, "New Adventure"/*, sf::Style::Titlebar | sf::Style::Close*/};
  // sf::View view{};
  // view.setCenter(0.f, 0.f);
  // view.zoom(.5f);
  // window.setView(view);
  window.setFramerateLimit(20);

  tson::Tileson t{};
  std::unique_ptr<tson::Map> map{ t.parse(fs::path{"assets"} / "maps" / "map1.json")};
  if (map->getStatus() != tson::ParseStatus::OK) {
    std::cerr << "Error loading map" << std::endl;
    return EXIT_FAILURE;
  }
    
  std::vector<tson::Layer*> layers{};
  layers.push_back(map->getLayer("Ground"));
  layers.push_back(map->getLayer("Terrain"));
  layers.push_back(map->getLayer("Objects"));
  tson::Tileset* overworldTileset{map->getTileset("overworld")};
  const fs::path& imgPath{overworldTileset->getFullImagePath()};
  sf::Texture overworldTexture{};
  if (!overworldTexture.loadFromFile(imgPath.string())) {
    std::cerr << "Error loading tileset image" << std::endl;
    return EXIT_FAILURE;
  }

  std::vector<sf::Sprite> sprites{};

  for (const auto& layer : layers) {
    for (auto& [pos, tile] : layer->getTileObjects()) {
      std::ignore = pos;
      tson::Rect rect{tile.getDrawingRect()};
      tson::Vector2f position{tile.getPosition()};
      sf::Sprite sprite{};
      sprite.setTexture(overworldTexture);
      sprite.setTextureRect({rect.x, rect.y, rect.width, rect.height});
      sprite.setPosition(position.x, position.y);
      sprites.push_back(std::move(sprite));
    }
  }

  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      const bool isCtrlPressed{sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)};
      const bool isAltPressed{sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)};
      const bool isWPressed{sf::Keyboard::isKeyPressed(sf::Keyboard::W)};
      const bool isQPressed{sf::Keyboard::isKeyPressed(sf::Keyboard::Q)};
      const bool isF4Pressed{sf::Keyboard::isKeyPressed(sf::Keyboard::F4)};

      if ((isCtrlPressed && (isWPressed || isQPressed)) || (isAltPressed && isF4Pressed)) {
        window.close();
        break;
      }
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      } else if (event.type == sf::Event::Resized) {
        winDims.width = event.size.width;
        winDims.height = event.size.height;
        // sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
        // window.setView(sf::View(visibleArea));
      }
    }
    window.clear();
    for (const auto& sprite : sprites) {
      window.draw(sprite);
    }
    window.display();
  }
}
