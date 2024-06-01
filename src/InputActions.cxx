#include "InputActions.hxx"

namespace my {
InputActions::InputActions(InputHandler& input) : input{input}, keyBindings{} {
  keyBindings.insert({Action::WalkUp, sf::Keyboard::Key::W});
  keyBindings.insert({Action::WalkDown, sf::Keyboard::Key::S});
  keyBindings.insert({Action::WalkLeft, sf::Keyboard::Key::A});
  keyBindings.insert({Action::WalkRight, sf::Keyboard::Key::D});
}

bool InputActions::getAction(const Action action) {
  if (action == Action::Quit) {
    const bool isAltF4{ input.isAltPressed() && input.isKeyPressed(sf::Keyboard::Key::F4) };
    const bool isCtrlQ{ input.isControlPressed() && input.isKeyPressed(sf::Keyboard::Key::Q) };
    const bool isCtrlW{ input.isControlPressed() && input.isKeyPressed(sf::Keyboard::Key::W) };
    return isAltF4 || isCtrlQ || isCtrlW;
  }
  return input.isKeyPressed(keyBindings.at(action));
}
} // namespace my
