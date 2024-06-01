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
const std::array<std::string, sf::Keyboard::Key::KeyCount> InputHandler::keyNames{
  "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
  "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
  "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9",
  "Escape", "LControl", "LShift", "LAlt", "LSystem",
  "RControl", "RShift", "RAlt", "RSystem", "Menu",
  "LBracket", "RBracket", "Semicolon", "Comma", "Period", "Apostrophe", "Slash", "Backslash",
  "Grave", "Equal", "Hyphen", "Space", "Enter", "Backspace", "Tab",
  "PageUp", "PageDown", "End", "Home", "Insert", "Delete",
  "Add", "Subtract", "Multiply", "Divide",
  "Left", "Right", "Up", "Down",
  "Numpad0", "Numpad1", "Numpad2", "Numpad3", "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9",
  "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15",
  "Pause",
};

InputHandler::InputHandler() :
  keyStates{},
  alt{ false },
  control{ false },
  shift{ false },
  system{ false }
{}

void InputHandler::onKeyDown(const sf::Event::KeyEvent& event) {
  if (event.code < 0 || event.code >= sf::Keyboard::Key::KeyCount) {
    LOGT("Invalid key pressed: " << event.code);
    return;
  }
  LOGT("Key pressed: " << keyNames.at(event.code));
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
  if (event.code < 0 || event.code >= sf::Keyboard::Key::KeyCount) {
    LOGT("Invalid key released: " << event.code);
    return;
  }
  LOGT("Key released: " << keyNames.at(event.code));
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
