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

  enum class State {
    Debounced = -1,
    Released = 0,
    Pressed
  };

  State walkUp;
  State walkDown;
  State walkLeft;
  State walkRight;
  State quit;
};
} // namespace my

#endif // INPUT_ACTIONS_HXX
