#ifndef INPUT_ACTIONS_HXX
#define INPUT_ACTIONS_HXX

#include <map>

#include "InputHandler.hxx"

namespace my {
class InputActions {
public:
  InputActions(InputHandler&);
  InputActions() = delete;
  InputActions(const InputActions&) = delete;
  InputActions(InputActions&&) noexcept = delete;
  InputActions& operator=(const InputActions&) = delete;
  InputActions& operator=(InputActions&&) noexcept = delete;

  enum class Action {
    WalkUp,
    WalkDown,
    WalkLeft,
    WalkRight,
    Quit,
  };

  bool getAction(const Action action);

private:
  InputHandler& input;
  std::map<Action, sf::Keyboard::Key> keyBindings;
};
} // namespace my

#endif // INPUT_ACTIONS_HXX
