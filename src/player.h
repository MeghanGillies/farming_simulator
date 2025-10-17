#pragma once

#include <string>

#include "farm_dimensions.h"

class Player {
private:
    FarmDimensions *farm_dimensions;
    int current_row = 0;
    int current_column = 0;
public:
    Player(FarmDimensions *dimensions);

    int row() const;
    int column() const;
    std::string symbol();

    void move_right();
    void move_left();
    void move_up();
    void move_down();
};
