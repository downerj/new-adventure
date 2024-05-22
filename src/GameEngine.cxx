#include "GameEngine.hxx"

#include <SFML/Window.hpp>

#include "Debug.hxx"

#ifdef DEBUG
#define LOGT(x) LOG(GameEngine, debug::fg::light::yellow, x)
#define LOGP(x) LOG_PART(GameEngine, debug::fg::light::yellow, x)
#define LOGC(x) LOG_CONTINUE(x)
#define LOGN() LOG_NEWLINE()
#else
#define LOGT(x)
#define LOGP(x)
#define LOGC(x)
#define LOGN()
#endif // DEBUG

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
      if (event.type == sf::Event::KeyPressed) {
        input.onKeyDown(event.key);
      } else if (event.type == sf::Event::KeyReleased) {
        input.onKeyUp(event.key);
      } else if (event.type == sf::Event::Closed) {
        renderer.window.close();
        break;
      } // else if (event.type == sf::Event::Resized) {
        // sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
        // window.setView(sf::View(visibleArea));
      // }

      if (input.actions.quit == State::Pressed) {
        renderer.window.close();
        break;
      } else if (input.actions.walkUp == State::Pressed) {
        LOGT("Walk up");
      } else if (input.actions.walkDown == State::Pressed) {
        LOGT("Walk down");
      } else if (input.actions.walkLeft == State::Pressed) {
        LOGT("Walk left");
      } else if (input.actions.walkRight == State::Pressed) {
        LOGT("Walk right");
      }
    }
    renderer.render();
  }
}
} // namespace my
