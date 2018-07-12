#include <tile.h>
#include <string>
#include <types.h>

Tile::Tile(std::string name, uint16 id) {
    this->name = std::move(name);
    this->id = id;
}

uint16 Tile::GetId() const {
    return id;
}
