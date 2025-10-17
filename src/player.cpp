#include <string>

#include "player.h"
#include "farm_dimensions.h"

Player::Player(FarmDimensions *dimensions) : farm_dimensions(dimensions){}

int Player::row() const {
    return current_row;
}

int Player::column() const {
    return current_column;
}

std::string Player::symbol() {
    return "🧑‍🌾";
}

void Player::move_right(){
    if (current_column != farm_dimensions->get_num_columns() - 1) {
        current_column += 1;
    }
}

void Player::move_down() {
    if (current_row != farm_dimensions->get_num_rows() - 1) {
        current_row += 1;
    }
}

void Player::move_left() {
    if (current_column != 0) {
        current_column -= 1;
    }
}

void Player::move_up() {
    if (current_row != 0) {
        current_row -= 1;
    }
}