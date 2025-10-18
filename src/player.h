#pragma once

#include <string>

#include "coordinate.h"
#include "farm_dimensions.h"

class Player {
private:
    FarmDimensions *farm_dimensions;
    Coordinate current_position = Coordinate(0, 0);
public:
    explicit Player(FarmDimensions *dimensions);

    Coordinate position() const;
    std::string symbol() const;

    void move_right();
    void move_left();
    void move_up();
    void move_down();
};
