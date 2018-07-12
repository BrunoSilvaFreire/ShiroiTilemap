#pragma once

#include "types.h"
#include <string>
#include <utility>

class Tile {
private:
    std::string name;
    uint16 id;
public:
    Tile(std::string name, uint16 id);

    uint16 GetId() const;
};