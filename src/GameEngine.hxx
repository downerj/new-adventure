#ifndef GAME_ENGINE_HXX
#define GAME_ENGINE_HXX

#include "ActionHandler.hxx"
#include "InputHandler.hxx"
#include "Renderer.hxx"

namespace my {
class GameEngine {
public:
  GameEngine();
  GameEngine(const GameEngine&) = delete;
  GameEngine(GameEngine&&) noexcept = delete;
  GameEngine& operator=(const GameEngine&) = delete;
  GameEngine& operator=(GameEngine&&) noexcept = delete;
  void loop();

private:
  Renderer renderer;
  ActionHandler actionHandler;
  InputHandler inputHandler;
};
} // namespace my

#endif // GAME_ENGINE_HXX
