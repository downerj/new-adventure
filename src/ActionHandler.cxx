#include "ActionHandler.hxx"

using namespace std;

namespace my {
using Action = ActionHandler::Action;
using State = ActionHandler::State;

ActionHandler::ActionHandler() : actions{} {
  for (auto& action : actions) {
    action = State::Released;
  }
}

State& ActionHandler::getActionState(const Action action) {
  return actions.at(static_cast<size_t>(action));
}

bool ActionHandler::isActionActive(const Action action) const {
  return actions.at(static_cast<size_t>(action)) == State::Pressed;
}

void ActionHandler::setActionState(const Action action, const State state) {
  actions.at(static_cast<size_t>(action)) = state;
}
} // namespace my
