#ifndef INPUT_HANDLER_HXX
#define INPUT_HANDLER_HXX

#include <map>

#include <SFML/Window.hpp>

#include "InputActions.hxx"

namespace my {
class InputHandler {
public:
  InputHandler();
  InputHandler(const InputHandler&) = delete;
  InputHandler(InputHandler&&) noexcept = delete;
  InputHandler& operator=(const InputHandler&) = delete;
  InputHandler& operator=(InputHandler&&) noexcept = delete;
  void onKeyDown(const sf::Event::KeyEvent&);
  void onKeyUp(const sf::Event::KeyEvent&);
  InputActions actions;

private:
  std::map<sf::Keyboard::Key, InputActions::State*> actionBindings;
};
} // namespace my

#endif // INPUT_HANDLER_HXX
