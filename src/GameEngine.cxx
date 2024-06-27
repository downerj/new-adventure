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

using namespace sf;

namespace my {
using Action = ActionHandler::Action;

GameEngine::GameEngine() :
  renderer{},
  actionHandler{},
  inputHandler{actionHandler}
{}

void GameEngine::loop() {
  while (renderer.window.isOpen()) {
    Event event{};
    while (renderer.window.pollEvent(event)) {
      if (event.type == Event::KeyPressed) {
        inputHandler.onKeyDown(event.key);
      } else if (event.type == Event::KeyReleased) {
        inputHandler.onKeyUp(event.key);
      // This is triggered by the X button and by Alt+F4.
      } else if (event.type == Event::Closed) {
        LOGT("Quit");
        renderer.window.close();
        break;
      }
      // else if (event.type == Event::Resized) {
      //   FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
      //   window.setView(View(visibleArea));
      // }
    }
    if (!renderer.window.isOpen()) {
      break;
    }
    if (actionHandler.isActionActive(Action::Quit)) {
      LOGT("Quit");
      renderer.window.close();
      break;
    } else if (actionHandler.isActionActive(Action::WalkUp)) {
      LOGT("Walk up");
    } else if (actionHandler.isActionActive(Action::WalkDown)) {
      LOGT("Walk down");
    } else if (actionHandler.isActionActive(Action::WalkLeft)) {
      LOGT("Walk left");
    } else if (actionHandler.isActionActive(Action::WalkRight)) {
      LOGT("Walk right");
    }
    renderer.render();
  }
}
} // namespace my
