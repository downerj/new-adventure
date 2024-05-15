#ifndef SPRITE_LOADER_HXX
#define SPRITE_LOADER_HXX

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include <tileson/tileson.hpp>

namespace my {
  class SpriteLoader {
  public:
    SpriteLoader();
    std::vector<sf::Sprite> sprites;

  private:
    tson::Tileson t;
    std::unique_ptr<tson::Map> map;
    std::vector<tson::Layer*> layers;
    tson::Tileset* overworldTileset;
    sf::Texture overworldTexture;
  };
}

#endif // SPRITE_LOADER_HXX
