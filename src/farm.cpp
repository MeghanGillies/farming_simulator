#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.h"

Farm::Farm(FarmDimensions *dimensions) : farm_dimensions(dimensions) {
    for (int i = 0; i < farm_dimensions->get_num_rows(); i++) {
        std::vector<Plot *> row;
        for (int j = 0; j < farm_dimensions->get_num_columns(); j++) {
            Soil *soil = new Soil();
            row.push_back(soil);
        }
        plots.push_back(row);
    }
}

int Farm::num_of_rows() {
    return farm_dimensions->get_num_rows();
}

int Farm::num_of_columns() {
    return farm_dimensions->get_num_columns();
}

std::string Farm::get_symbol(int row, int column) {
    return plots.at(row).at(column)->symbol();
}

void Farm::plant(int row, int column, Plot *plot) {
    Plot *current_plot = plots.at(row).at(column);
    plots.at(row).at(column) = plot;
    delete current_plot;
}

void Farm::harvest(int row, int column) {
    Plot *current_plot = plots.at(row).at(column);

    if (current_plot != dynamic_cast<Soil*>(current_plot) ) {
        Soil *soil = new Soil();
        plots.at(row).at(column) = soil;
        delete current_plot;
    }
}