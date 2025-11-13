#pragma once

#include <string>
#include <vector>
#include <map>

#include "vegetable.h"
#include "soil.h"
#include "farm_dimensions.h"
#include "coordinate.h"

class Farm {
private:
    FarmDimensions *farm_dimensions;
    std::vector<std::vector<Soil *>> soil_grid;
    std::map<Coordinate, Vegetable *> vegetables;
    int day_count = 1;
public:
    explicit Farm(FarmDimensions *dimensions);
    ~Farm();

    int num_of_rows() const;
    int num_of_columns() const;
    std::string get_symbol(Coordinate coord) const;
    int get_day_count() const;

    void plant(Coordinate coord, Vegetable *veggie);
    void water(Coordinate coord);
    void harvest(Coordinate coord);
    void end_day();
};