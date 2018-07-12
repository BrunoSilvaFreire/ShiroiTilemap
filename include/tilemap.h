#pragma once

#include <vector>
#include "types.h"
#include "tile.h"

class TileMap {
private:
    uint32 width;
    uint32 height;
    uint16 *cached_map;
    std::vector<Tile *> tiles;
public:
    TileMap(uint32 width, uint32 height);

    ~TileMap();

    void Resize(uint32 new_width, uint32 new_height);

    bool IsOutOfBounds(uint32 x, uint32 y);

    bool IsOutOfBounds(uint32 index);

    uint64 GetArea();

    uint32 IndexOf(uint32 x, uint32 y);

    uint16 GetTile(uint32 x, uint32 y);

    uint16 GetTile(uint32 index);

    void AddTileType(Tile *tile);

    uint32 GetTotalTileTypes();

    Tile *GetTileType(uint16 id);
};