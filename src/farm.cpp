#include <string>
#include <vector>

#include "farm.hpp"
#include "coordinate.h"
#include "plot.h"
#include "soil.h"

// Farm Constructor
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

// Farm Destructor
Farm::~Farm() {
    for (int i = 0; i < farm_dimensions->get_num_rows(); i++) {
        for (int j = 0; j < farm_dimensions->get_num_columns(); j++) {
            delete plots.at(i).at(j);
        }
    }
}

int Farm::num_of_rows() const {
    return farm_dimensions->get_num_rows();
}

int Farm::num_of_columns() const {
    return farm_dimensions->get_num_columns();
}

std::string Farm::get_symbol(Coordinate coord) const {
    return plots.at(coord.row_index).at(coord.column_index)->symbol();
}

int Farm::get_day_count() const {
    return day_count;
}

void Farm::plant(Coordinate coord, Plot *plot) {
    Plot *current_plot = plots.at(coord.row_index).at(coord.column_index);

    if ( current_plot == dynamic_cast<Soil*>(current_plot) ) {
        plots.at(coord.row_index).at(coord.column_index) = plot;
        delete current_plot;
    }
}

void Farm::water(Coordinate coord) {
    Plot *current_plot = plots.at(coord.row_index).at(coord.column_index);
    current_plot->water();
}

void Farm::harvest(Coordinate coord) {
    Plot *current_plot = plots.at(coord.row_index).at(coord.column_index);

    if ( current_plot != dynamic_cast<Soil*>(current_plot) && current_plot->symbol() != tilled_soil && current_plot->symbol() != baby ) {
        Soil *soil = new Soil();
        plots.at(coord.row_index).at(coord.column_index) = soil;
        delete current_plot;
    }
}

void Farm::end_day() {
    day_count += 1;

    for (int i = 0; i < farm_dimensions->get_num_rows(); i++) {
        for (int j = 0; j < farm_dimensions->get_num_columns(); j++) {
            plots.at(i).at(j)->end_day();
        }
    }
}