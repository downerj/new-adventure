#ifndef INPUT_HANDLER_HXX
#define INPUT_HANDLER_HXX

#include <array>
#include <initializer_list>

#include <SFML/Window.hpp>

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
  bool isKeyPressed(sf::Keyboard::Key);
  bool areKeysPressed(std::initializer_list<sf::Keyboard::Key>);
  bool isAltPressed();
  bool isControlPressed();
  bool isShiftPressed();
  bool isSystemPressed();

  enum class State {
    Debounced = -1,
    Released = 0,
    Pressed = 1,
  };

private:
  std::array<State, sf::Keyboard::Key::KeyCount> keyStates;
  bool alt;
  bool control;
  bool shift;
  bool system;
};
} // namespace my

#endif // INPUT_HANDLER_HXX
