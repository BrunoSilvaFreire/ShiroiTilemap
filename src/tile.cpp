#include <tile.h>
#include <string>
#include <types.h>

Tile::Tile(std::string name, uint32 id) {
    this->name = std::move(name);
    this->id = id;
}
