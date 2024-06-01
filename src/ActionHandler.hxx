#ifndef INPUT_ACTIONS_HXX
#define INPUT_ACTIONS_HXX

#include <map>

#include "InputHandler.hxx"

namespace my {
class ActionHandler {
public:
  ActionHandler(InputHandler&);
  ActionHandler() = delete;
  ActionHandler(const ActionHandler&) = delete;
  ActionHandler(ActionHandler&&) noexcept = delete;
  ActionHandler& operator=(const ActionHandler&) = delete;
  ActionHandler& operator=(ActionHandler&&) noexcept = delete;

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
