#pragma once

#include "coordinate.h"
#include "farm_dimensions.h"

class Bunny {
private:
    Coordinate starting_position;
    Coordinate current_position;
    FarmDimensions *farm_dimensions;

    void move_right();
    void move_left();
    void move_up();
    void move_down();
public:
    Bunny(Coordinate coord, FarmDimensions *dimensions);

    Coordinate position() const;
    std::string symbol() const;

    void move();
    void flee(Coordinate player_positon);
    bool is_out_of_bounds();
};