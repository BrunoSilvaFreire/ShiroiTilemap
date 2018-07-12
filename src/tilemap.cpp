#include "tilemap.h"
#include "../include/tilemap.h"

TileMap::TileMap(uint32 width, uint32 height) {
    this->width = width;
    this->height = height;
    this->tiles = std::vector<Tile>();
    this->cached_map = (uint16 *) malloc(width * height * sizeof(uint16));
}

uint32 TileMap::IndexOf(uint32 x, uint32 y) {
    return y * width + x;
}

uint16 TileMap::GetTile(uint32 x, uint32 y) {
    return GetTile(IndexOf(x, y));
}

bool TileMap::IsOutOfBounds(uint32 x, uint32 y) {
    return IsOutOfBounds(IndexOf(x, y));
}

bool TileMap::IsOutOfBounds(uint32 index) {
    return index >= GetArea();
}

uint64 TileMap::GetArea() {
    return width * height;
}

uint16 TileMap::GetTile(uint32 index) {
    return *(cached_map + index);
}

void TileMap::Resize(uint32 new_width, uint32 new_height) {
    realloc(cached_map, new_width * new_height * sizeof(uint16));
}
