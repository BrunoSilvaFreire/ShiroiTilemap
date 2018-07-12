#pragma once

#include "types.h"
#include <string>
#include <utility>

class Tile {
private:
    std::string name;
    uint32 id;
public:
    Tile(std::string name, uint32 id);

    uint32 GetId() const;
};