#ifndef INPUT_HANDLER_HXX
#define INPUT_HANDLER_HXX

#include <array>
#include <initializer_list>
#include <map>
#include <string>

#include <SFML/Window.hpp>

#include "ActionHandler.hxx"

namespace my {
class InputHandler {
public:
  InputHandler(ActionHandler&);
  InputHandler() = delete;
  InputHandler(const InputHandler&) = delete;
  InputHandler(InputHandler&&) noexcept = delete;
  InputHandler& operator=(const InputHandler&) = delete;
  InputHandler& operator=(InputHandler&&) noexcept = delete;
  void onKeyDown(const sf::Event::KeyEvent&);
  void onKeyUp(const sf::Event::KeyEvent&);

  static const std::array<std::string, sf::Keyboard::Key::KeyCount> keyNames;

private:
  ActionHandler& actions;
  std::map<sf::Keyboard::Key, ActionHandler::Action> keyBindings;
};
} // namespace my

#endif // INPUT_HANDLER_HXX
