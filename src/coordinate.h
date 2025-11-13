#pragma once

struct Coordinate {
    int row_index;
    int column_index;

    Coordinate(int row, int column) : row_index(row), column_index(column) {}

    bool operator==(Coordinate coord) const {
        if (row_index == coord.row_index && column_index == coord.column_index) {
            return true;
        } else {
            return false;
        }
    }
};