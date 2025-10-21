#include <string>
#include <vector>

#include "farm.hpp"
#include "coordinate.h"
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
    return plots.at(coord.rowIndex).at(coord.columnIndex)->symbol();
}

void Farm::plant(Coordinate coord, Plot *plot) {
    Plot *current_plot = plots.at(coord.rowIndex).at(coord.columnIndex);

    if ( current_plot == dynamic_cast<Soil*>(current_plot) ) {
        plots.at(coord.rowIndex).at(coord.columnIndex) = plot;
        delete current_plot;
    }
}

void Farm::harvest(Coordinate coord) {
    Plot *current_plot = plots.at(coord.rowIndex).at(coord.columnIndex);

    if ( current_plot != dynamic_cast<Soil*>(current_plot) && current_plot->symbol() != baby ) {
        Soil *soil = new Soil();
        plots.at(coord.rowIndex).at(coord.columnIndex) = soil;
        delete current_plot;
    }
}

void Farm::end_day() {
    for (int i = 0; i < farm_dimensions->get_num_rows(); i++) {
        for (int j = 0; j < farm_dimensions->get_num_columns(); j++) {
            plots.at(i).at(j)->end_day();
        }
    }
}