#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <tileson.hpp>

using namespace std;
using namespace sf;
namespace fs = filesystem;
using uint = unsigned int;

struct Dimensions {
  uint width;
  uint height;
};

int main(int, char**) {
  Dimensions winDims{600u, 600u};
  const VideoMode winMode{winDims.width, winDims.height};
  RenderWindow window{winMode, "New Adventure"};
  View view{window.getDefaultView()};
  window.setFramerateLimit(20);

  while (window.isOpen()) {
    Event event{};
    while (window.pollEvent(event)) {
      const bool isCtrlPressed{Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl)};
      const bool isAltPressed{Keyboard::isKeyPressed(Keyboard::LAlt) || Keyboard::isKeyPressed(Keyboard::RAlt)};
      const bool isWPressed{Keyboard::isKeyPressed(Keyboard::W)};
      const bool isQPressed{Keyboard::isKeyPressed(Keyboard::Q)};
      const bool isF4Pressed{Keyboard::isKeyPressed(Keyboard::F4)};

      if ((isCtrlPressed && (isWPressed || isQPressed)) || (isAltPressed && isF4Pressed)) {
        window.close();
        break;
      }
      if (event.type == Event::Closed) {
        window.close();
        break;
      } else if (event.type == Event::Resized) {
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
