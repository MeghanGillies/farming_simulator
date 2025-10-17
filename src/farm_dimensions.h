#pragma once

class FarmDimensions {
private:
    int num_rows;
    int num_columns;
public:
    FarmDimensions(int rows, int columns);
    int get_num_rows() const;
    int get_num_columns() const;
};