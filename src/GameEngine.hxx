#ifndef GAME_ENGINE_HXX
#define GAME_ENGINE_HXX

#include "Renderer.hxx"

class GameEngine {
public:
  GameEngine();
  void loop();

private:
  Renderer renderer;
};

#endif // GAME_ENGINE_HXX
