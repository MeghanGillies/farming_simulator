#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.h"

Farm::Farm(int num_rows, int num_columns) : rows(num_rows), columns(num_columns) {
    for (int i = 0; i < rows; i++) {
        std::vector<Plot *> row;
        for (int j = 0; j < columns; j++) {
            Soil *soil = new Soil();
            row.push_back(soil);
        }
        plots.push_back(row);
    }
}

int Farm::num_of_rows() {
    return rows;
}

int Farm::num_of_columns() {
    return columns;
}

std::string Farm::get_symbol(int row, int column) {
    return plots.at(row).at(column)->symbol();
}