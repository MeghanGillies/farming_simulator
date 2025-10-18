#pragma once

struct Coordinate {
    int rowIndex;
    int columnIndex;

    Coordinate(int row, int column) : rowIndex(row), columnIndex(column) {}

    bool is_equal(Coordinate coord) const {
        if (rowIndex == coord.rowIndex && columnIndex == coord.columnIndex) {
            return true;
        } else {
            return false;
        }
    }
};