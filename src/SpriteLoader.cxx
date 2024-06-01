#include "SpriteLoader.hxx"

#include <filesystem>
#include <tuple>

namespace fs = std::filesystem;
using namespace sf;
using namespace std;

namespace my {
SpriteLoader::SpriteLoader() :
  sprites{},
  t{},
  map{ move(t.parse(fs::path{ "assets" } / "maps" / "map1.json")) },
  layers{},
  overworldTileset{},
  overworldTexture{}
{
  if (map->getStatus() != tson::ParseStatus::OK) {
    throw runtime_error{ "Error loading map" };
  }

  layers.push_back(map->getLayer("Ground"));
  layers.push_back(map->getLayer("Terrain"));
  layers.push_back(map->getLayer("Objects"));
  overworldTileset = map->getTileset("overworld");
  const fs::path& imgPath{ overworldTileset->getFullImagePath() };
  if (!overworldTexture.loadFromFile(imgPath.string())) {
    throw runtime_error{ "Error loading tileset image" };
  }

  for (const auto& layer : layers) {
    for (const auto& [pos, tile] : layer->getTileObjects()) {
      ignore = pos;
      const tson::Rect rect{ tile.getDrawingRect() };
      const tson::Vector2f position{ tile.getPosition() };
      Sprite sprite{};
      sprite.setTexture(overworldTexture);
      sprite.setTextureRect({ rect.x, rect.y, rect.width, rect.height });
      sprite.setPosition(position.x, position.y);
      sprites.push_back(move(sprite));
    }
  }
}
} // namespace my
