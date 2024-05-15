#include "GameEngine.hxx"

#include <SFML/Window.hpp>

#include "Debug.hxx"

namespace my {
using State = InputActions::State;

GameEngine::GameEngine() :
  renderer{},
  input{}
{}

void GameEngine::loop() {
  while (renderer.window.isOpen()) {
    sf::Event event{};
    while (renderer.window.pollEvent(event)) {
      // const bool isCtrlPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) };
      // const bool isAltPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt) };
      // const bool isWPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::W) };
      // const bool isQPressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::Q) };
      // const bool isF4Pressed{ sf::Keyboard::isKeyPressed(sf::Keyboard::F4) };
      // if ((isCtrlPressed && (isWPressed || isQPressed)) || (isAltPressed && isF4Pressed)) {
      //   renderer.window.close();
      //   break;
      // }
      if (event.type == sf::Event::KeyPressed) {
        input.onKeyDown(event.key);
      } else if (event.type == sf::Event::KeyReleased) {
        input.onKeyUp(event.key);
      } else if (event.type == sf::Event::Closed) {
        renderer.window.close();
        break;
      } else if (event.type == sf::Event::Resized) {
        // sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
        // window.setView(sf::View(visibleArea));
      }

      if (input.actions.quit == State::Pressed) {
        renderer.window.close();
        break;
      } else if (input.actions.walkUp == State::Pressed) {
        DEBUG_LINE("Walk up");
      } else if (input.actions.walkDown == State::Pressed) {
        DEBUG_LINE("Walk down");
      } else if (input.actions.walkLeft == State::Pressed) {
        DEBUG_LINE("Walk left");
      } else if (input.actions.walkRight == State::Pressed) {
        DEBUG_LINE("Walk right");
      }
    }
    renderer.render();
  }
}
} // namespace my
