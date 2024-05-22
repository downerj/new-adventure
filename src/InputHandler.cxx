#include "InputHandler.hxx"

#include "Debug.hxx"

#ifdef DEBUG
#define LOGT(x) LOG(InputHandler, debug::fg::light::cyan, x)
#define LOGP(x) LOG_PART(InputHandler, debug::fg::light::cyan, x)
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

InputHandler::InputHandler() :
  actions{},
  actionBindings{}
{
  actionBindings.insert({ sf::Keyboard::Key::W, &actions.walkUp });
  actionBindings.insert({ sf::Keyboard::Key::S, &actions.walkDown });
  actionBindings.insert({ sf::Keyboard::Key::A, &actions.walkLeft });
  actionBindings.insert({ sf::Keyboard::Key::D, &actions.walkRight });
}

void InputHandler::onKeyDown(const sf::Event::KeyEvent& event) {
  const bool isAltF4{event.alt && event.code == sf::Keyboard::Key::F4};
  const bool isCtrlQ{event.control && event.code == sf::Keyboard::Key::Q};
  const bool isCtrlW{event.control && event.code == sf::Keyboard::Key::W};
  if (isAltF4 || isCtrlQ || isCtrlW) {
    actions.quit = State::Pressed;
  }
  auto it = actionBindings.find(event.code);
  if (it != actionBindings.end() && *(it->second) != State::Debounced) {
    LOGT("Key #" << event.code << " pressed");
    *(it->second) = State::Pressed;
  }
}

void InputHandler::onKeyUp(const sf::Event::KeyEvent& event) {
  auto it = actionBindings.find(event.code);
  if (it != actionBindings.end()) {
    LOGT("Key #" << event.code << " released");
    *(it->second) = State::Released;
  }
}
} // namespace my
