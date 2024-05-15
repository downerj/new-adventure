#ifndef GAME_ENGINE_HXX
#define GAME_ENGINE_HXX

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
  };
}

#endif // GAME_ENGINE_HXX
