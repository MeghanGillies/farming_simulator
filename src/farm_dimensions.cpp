#include "farm_dimensions.h"

FarmDimensions::FarmDimensions(int rows, int columns) :
    num_rows(rows),
    num_columns(columns)
{}

int FarmDimensions::get_num_rows() const {
    return num_rows;
}

int FarmDimensions::get_num_columns() const {
    return num_columns;
}