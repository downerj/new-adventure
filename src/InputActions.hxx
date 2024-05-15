#ifndef INPUT_ACTIONS_HXX
#define INPUT_ACTIONS_HXX

namespace my {
  class InputActions {
  public:
    InputActions();
    InputActions(const InputActions&) = delete;
    InputActions(InputActions&&) noexcept = delete;
    InputActions& operator=(const InputActions&) = delete;
    InputActions& operator=(InputActions&&) noexcept = delete;

    bool walkUp;
    bool walkDown;
    bool walkLeft;
    bool walkRight;
    bool quit;
  };
}

#endif // INPUT_ACTIONS_HXX
