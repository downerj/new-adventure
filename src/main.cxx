#include <cstdlib>
#include <filesystem>
#include <memory>

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
  my::Dimensions winDims{600u, 600u};
  const sf::VideoMode winMode{winDims.width, winDims.height};
  sf::RenderWindow window{winMode, "New Adventure"};
  sf::View view{window.getDefaultView()};
  window.setFramerateLimit(20);

  tson::Tileson t{};
  std::unique_ptr<tson::Map> map{t.parse(fs::path{"./assets/maps/map1.json"})};
  if (map->getStatus() != tson::ParseStatus::OK) {
    std::cerr << "Error loading map" << std::endl;
    return EXIT_FAILURE;
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
        view.setSize(winDims.width * 1.f, winDims.height * 1.f);
        view.setCenter(winDims.width / 2.f, winDims.height / 2.f);
        window.setView(view);
      }
    }
    window.display();
  }
}
