#pragma once

struct Coordinate {
    int rowIndex;
    int columnIndex;

    Coordinate(int row, int column) : rowIndex(row), columnIndex(column) {}
};