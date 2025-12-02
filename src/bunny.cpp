#include "bunny.h"
#include "farm_dimensions.h"

// Different Directions of Movement
void Bunny::move_right() { current_position.column_index += 1; }
void Bunny::move_left() { current_position.column_index -= 1; }
void Bunny::move_up() { current_position.row_index -= 1; }
void Bunny::move_down() { current_position.row_index += 1; }

// Constructor
Bunny::Bunny(Coordinate coord, FarmDimensions *dimensions) :
    farm_dimensions(dimensions),
    starting_position(coord),
    current_position(coord) {}

Coordinate Bunny::position() const { return current_position; }
std::string Bunny::symbol() const { return "🐇"; }

// Bunny will always move in a straight line, with the
// direction dependent on which edge of the farm the
// Bunny Spawns on
void Bunny::move() {
    if ( starting_position.column_index == 0 ) {
        // Spawns on LEFT-EDGE
        move_right();
    } else if ( starting_position.column_index == farm_dimensions->get_num_columns() - 1 ) {
        // Spawns on RIGHT-EDGE
        move_left();
    } else if ( starting_position.row_index == 0 ) {
        // Spawns on TOP-EDGE
        move_down();
    } else if ( starting_position.row_index == farm_dimensions->get_num_rows() - 1 ) {
        // Spawns on BOTTOM-EDGE
        move_up();
    }
}

void Bunny::flee(Coordinate player_positon) {
    if ( player_positon == Coordinate (current_position.row_index, current_position.column_index - 1) ) {
        // Player is to the LEFT of the Bunny.
        // Bunny moves 4 RIGHT to flee.
        for ( int i = 0; i < 4; i++) {
            move_right();
        }
    } else if ( player_positon == Coordinate (current_position.row_index, current_position.column_index + 1) ) {
        // Player is to the RIGHT of the Bunny.
        // Bunny moves 4 LEFT to flee.
        for ( int i = 0; i < 4; i++) {
            move_left();
        }
    } else if ( player_positon == Coordinate (current_position.row_index - 1, current_position.column_index) ) {
        // Player is to the ABOVE of the Bunny.
        // Bunny moves 4 DOWN to flee.
        for ( int i = 0; i < 4; i++) {
            move_down();
        }
    } else if ( player_positon == Coordinate (current_position.row_index + 1, current_position.column_index) ) {
        // Player is to the BELOW of the Bunny.
        // Bunny moves 4 UP to flee.
        for ( int i = 0; i < 4; i++) {
            move_up();
        }
    }
}

bool Bunny::is_out_of_bounds() const {
    if ( current_position.row_index >= farm_dimensions->get_num_rows() ) {
        // Out of bounds BELOW farm
        return true;
    } else if ( current_position.row_index < 0 ) {
        // Out of bounds ABOVE farm
        return true;
    } else if ( current_position.column_index >= farm_dimensions->get_num_columns() ) {
        // Out of bounds to the RIGHT of the farm
        return true;
    } else if ( current_position.column_index < 0 ) {
        // Out of bounds to the LEFT of the farm
        return true;
    } else {
        // Within bounds of the farm
        return false;
    }
}