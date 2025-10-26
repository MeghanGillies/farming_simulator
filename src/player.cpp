#include <string>

#include "player.h"
#include "coordinate.h"
#include "farm_dimensions.h"

Player::Player(FarmDimensions *dimensions) : farm_dimensions(dimensions) {}

Coordinate Player::position() const {
    return current_position;
}

std::string Player::symbol() const {
    return "🧑‍🌾";
}

void Player::move_right(){
    if (current_position.column_index != farm_dimensions->get_num_columns() - 1) {
        current_position.column_index += 1;
    }
}

void Player::move_left() {
    if (current_position.column_index != 0) {
        current_position.column_index -= 1;
    }
}

void Player::move_up() {
    if (current_position.row_index != 0) {
        current_position.row_index -= 1;
    }
}

void Player::move_down() {
    if (current_position.row_index != farm_dimensions->get_num_rows() - 1) {
        current_position.row_index += 1;
    }
}