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
  SpriteLoader(const SpriteLoader&) = delete;
  SpriteLoader(SpriteLoader&&) noexcept = delete;
  SpriteLoader& operator=(const SpriteLoader&) = delete;
  SpriteLoader& operator=(SpriteLoader&&) noexcept = delete;
  std::vector<sf::Sprite> sprites;

private:
  tson::Tileson t;
  std::unique_ptr<tson::Map> map;
  std::vector<tson::Layer*> layers;
  tson::Tileset* overworldTileset;
  sf::Texture overworldTexture;
};
} // namespace my

#endif // SPRITE_LOADER_HXX
