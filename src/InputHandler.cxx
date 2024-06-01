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
InputHandler::InputHandler() : keyStates{} {}

void InputHandler::onKeyDown(const sf::Event::KeyEvent& event) {
  LOGT("Key #" << event.code << " pressed");
  if (event.code < 0 || event.code >= sf::Keyboard::Key::KeyCount) {
    LOGT("Invalid key");
    return;
  }
  State& key = keyStates.at(event.code);
  if (key != State::Debounced) {
    key = State::Pressed;
  }
  alt = event.alt;
  control = event.control;
  shift = event.shift;
  system = event.system;
}

void InputHandler::onKeyUp(const sf::Event::KeyEvent& event) {
  LOGT("Key #" << event.code << " released");
  if (event.code < 0 || event.code >= sf::Keyboard::Key::KeyCount) {
    LOGT("Invalid key");
    return;
  }
  keyStates.at(event.code) = State::Released;
  alt = event.alt;
  control = event.control;
  shift = event.shift;
  system = event.system;
}

bool InputHandler::isKeyPressed(sf::Keyboard::Key key) {
  return keyStates.at(key) == State::Pressed;
}

bool InputHandler::areKeysPressed(std::initializer_list<sf::Keyboard::Key> keys) {
  for (const auto& key : keys) {
    if (keyStates.at(key) != State::Pressed) {
      return false;
    }
  }
  return true;
}

bool InputHandler::isAltPressed() { return alt; }
bool InputHandler::isControlPressed() { return control; }
bool InputHandler::isShiftPressed() { return shift; }
bool InputHandler::isSystemPressed() { return system; }
} // namespace my
