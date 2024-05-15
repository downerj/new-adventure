#include "InputHandler.hxx"

namespace my {
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
    actions.quit = true;
  }
  if (actionBindings.find(event.code) != actionBindings.end()) {
    *actionBindings[event.code] = true;
  }
}

void InputHandler::onKeyUp(const sf::Event::KeyEvent& event) {
  if (actionBindings.find(event.code) != actionBindings.end()) {
    *actionBindings[event.code] = false;
  }
}
} // namespace my
