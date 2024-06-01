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

using namespace sf;
using namespace std;
using KB = sf::Keyboard;
using Key = sf::Keyboard::Key;

namespace my {
using Action = ActionHandler::Action;
using State = ActionHandler::State;

const array<string, Key::KeyCount> InputHandler::keyNames{
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

InputHandler::InputHandler(ActionHandler& actions) : actions{ actions }, keyBindings{} {
  keyBindings.insert({ Key::W, Action::WalkUp });
  keyBindings.insert({ Key::S, Action::WalkDown });
  keyBindings.insert({ Key::A, Action::WalkLeft });
  keyBindings.insert({ Key::D, Action::WalkRight });
}

void InputHandler::onKeyDown(const Event::KeyEvent& event) {
  if (event.code < 0 || event.code >= Key::KeyCount) {
    LOGT("Invalid key pressed: " << event.code);
    return;
  }
  LOGT("Key pressed: " << keyNames.at(event.code));
  
  // Check for quit combo.
  const bool isCtrlQ{ event.control && event.code == Key::Q };
  const bool isCtrlW{ event.control && event.code == Key::W };
  if (isCtrlQ || isCtrlW) {
    actions.setActionState(Action::Quit, State::Pressed);
    return;
  }

  auto it{ keyBindings.find(event.code) };
  if (it == keyBindings.end()) {
    return;
  }
  State& state{ actions.getActionState(it->second) };
  if (state != State::Debounced) {
    state = State::Pressed;
  }
}

void InputHandler::onKeyUp(const Event::KeyEvent& event) {
  if (event.code < 0 || event.code >= Key::KeyCount) {
    LOGT("Invalid key released: " << event.code);
    return;
  }
  LOGT("Key released: " << keyNames.at(event.code));
  auto it{ keyBindings.find(event.code) };
  if (it == keyBindings.end()) {
    return;
  }
  actions.setActionState(it->second, State::Released);
}
} // namespace my
