#pragma once

#include <string>
#include <vector>

#include "plot.h"
#include "farm_dimensions.h"

class Farm {
private:
    FarmDimensions *farm_dimensions;
    std::vector<std::vector<Plot *>> plots;

public:
    explicit Farm(FarmDimensions *dimensions);
    int num_of_rows();
    int num_of_columns();
    std::string get_symbol(int row, int column);
    void plant(int row, int column, Plot *plot);
    void harvest(int row, int column);
};