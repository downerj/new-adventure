#include "InputHandler.hxx"

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
    *(it->second) = State::Pressed;
  }
}

void InputHandler::onKeyUp(const sf::Event::KeyEvent& event) {
  auto it = actionBindings.find(event.code);
  if (it != actionBindings.end()) {
    *(it->second) = State::Released;
  }
}
} // namespace my
