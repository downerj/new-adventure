#ifndef ACTION_HANDLER_HXX
#define ACTION_HANDLER_HXX

#include <array>

namespace my {
class ActionHandler {
public:
  ActionHandler();
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
    ActionCount
  };

  enum class State {
    Released,
    Pressed,
    Debounced,
  };

  State& getActionState(const Action action);
  bool isActionActive(const Action action) const;

private:
  std::array<State, static_cast<std::size_t>(Action::ActionCount)> actions;

  friend class InputHandler;
  void setActionState(const Action action, const State state);
};
} // namespace my

#endif // ACTION_HANDLER_HXX
