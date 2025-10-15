#pragma once

#include <string>
#include <vector>

#include "plot.h"

class Farm {
private:
    const int rows;
    const int columns;
    std::vector<std::vector<Plot *>> plots;

public:
    Farm(int num_rows, int num_columns);
    int num_of_rows();
    int num_of_columns();
    std::string get_symbol(int row, int column);
};