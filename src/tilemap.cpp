#include <logging.h>
#include <iostream>
#include "tilemap.h"
#include "../include/tilemap.h"

TileMap::TileMap(uint32 width, uint32 height) {
    this->width = width;
    this->height = height;
    this->total_tiles = 0;
    this->tiles = (Tile *) malloc(0);
    this->map = (uint16 *) malloc(width * height * sizeof(uint16));
}

uint64 TileMap::IndexOf(uint32 x, uint32 y) {
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

uint16 TileMap::GetTile(uint64 index) {
    return *(map + index);
}

void TileMap::Resize(uint32 new_width, uint32 new_height) {
    realloc(map, new_width * new_height * sizeof(uint16));
}

Tile *TileMap::GetTileType(uint16 id) {
    for (int i = 0; i < total_tiles; ++i) {
        auto tile = (tiles + i);
        if (tile->GetId() == id) {
            return tile;
        }
    }
    return nullptr;
}

void TileMap::AddTileType(Tile *tile) {
    auto new_size = (total_tiles + 1) * sizeof(Tile *);
    realloc(tiles, new_size);
    *(tiles + total_tiles) = *tile;
    total_tiles++;
}

uint32 TileMap::GetTotalTileTypes() {
    return total_tiles;
}

TileMap::~TileMap() {
    free(tiles);
    free(map);
}

void TileMap::RemoveTileType(Tile *tile) {
    uint32 index = TileIndexOf(tile);
    for (int i = index; i < total_tiles; ++i) {
        if (i <= 0) {
            continue;
        }
        tiles[i - 1] = tiles[i];
    }
    auto newSize = --total_tiles * sizeof(Tile *);
    realloc(tile, newSize);
}

uint32 TileMap::TileIndexOf(Tile *tile) {
    for (uint32 i = 0; i < total_tiles; ++i) {
        auto t = (tiles + i);
        if (t->GetId() == t->GetId()) {
            return i;
        }
    }
    return UINT32_MAX;
}
