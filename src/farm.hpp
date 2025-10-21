#pragma once

#include <string>
#include <vector>

#include "plot.h"
#include "farm_dimensions.h"
#include "coordinate.h"

class Farm {
private:
    FarmDimensions *farm_dimensions;
    std::vector<std::vector<Plot *>> plots;
    std::string baby = "🌱";

public:
    explicit Farm(FarmDimensions *dimensions);
    ~Farm();

    int num_of_rows() const;
    int num_of_columns() const;
    std::string get_symbol(Coordinate coord) const;

    void plant(Coordinate coord, Plot *plot);
    void harvest(Coordinate coord);
    void end_day();
};