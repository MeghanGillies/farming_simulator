#pragma once

#include <iostream>

struct Coordinate {
    int row_index;
    int column_index;

    Coordinate(int row, int column) : row_index(row), column_index(column) {}

    bool operator==(const Coordinate &coord) const {
        if (row_index == coord.row_index && column_index == coord.column_index) {
            return true;
        }
        return false;
    }

    bool operator<(const Coordinate &coord) const {
        if (row_index != coord.row_index) {
            return row_index < coord.row_index;
        }
        return column_index < coord.column_index;
    }

    bool operator>(const Coordinate &coord) const {
        if (row_index != coord.row_index) {
            return row_index > coord.row_index;
        }
        return column_index > coord.column_index;
    }
};