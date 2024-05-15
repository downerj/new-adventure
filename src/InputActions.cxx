#include "InputActions.hxx"

namespace my {
InputActions::InputActions() :
  walkUp{State::Released},
  walkDown{State::Released},
  walkLeft{State::Released},
  walkRight{State::Released},
  quit{State::Released}
{}
} // namespace my
