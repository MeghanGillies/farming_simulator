#include "bunny_manager.h"

// Makes sure the Bunny doesn't spawn on the same coordinate as the Player
Coordinate BunnyManager::validate_bunny_coord( bool row_is_rand, Coordinate bunny_coord, Coordinate player_coord ) const {
    int row = bunny_coord.row_index;
    int column = bunny_coord.column_index;

    bool valid_coord = false;

    while (!valid_coord) {
        if ( row_is_rand ) {
            row = random->generate_int() % farm_dimensions->get_num_columns();

        } else {
            column = random->generate_int() % farm_dimensions->get_num_columns();
        }

        if ( Coordinate(row, column) != player_coord ) {
            valid_coord = true;
        }
    }

    return Coordinate(row, column);
}


// Constructor
BunnyManager::BunnyManager(Bunny **b, FarmDimensions *dimensions , Farm *f, Random *r) :
    bunny(b),
    farm_dimensions(dimensions),
    farm(f),
    random(r)
{}

// Will randomly spawn the Bunny on one of the 4 edges of the farm
void BunnyManager::spawn_bunny(Coordinate player_coord) {
    if (*bunny == nullptr) {
        int spawn_chance = random->generate_int() % 4;

        if (spawn_chance == 0) { // 25% chance
            int side_choice = random->generate_int() % 4;

            if (side_choice == 0) {
                // Top
                int row = 0;
                int column = -1;

                Coordinate bunny_coord = validate_bunny_coord(false, Coordinate(row, column), player_coord);
                *bunny = new Bunny(bunny_coord, farm_dimensions);

            } else if (side_choice == 1) {
                // Bottom
                int row = farm_dimensions->get_num_rows() - 1;
                int column = -1;

                Coordinate bunny_coord = validate_bunny_coord(false, Coordinate(row, column), player_coord);
                *bunny = new Bunny(bunny_coord, farm_dimensions);

            } else if (side_choice == 2) {
                // Left
                int row = -1;
                int column = 0;

                Coordinate bunny_coord = validate_bunny_coord(true, Coordinate(row, column), player_coord);
                *bunny = new Bunny(bunny_coord, farm_dimensions);

            } else if (side_choice == 3) {
                // Right
                int row = -1;
                int column = farm_dimensions->get_num_columns() - 1;

                Coordinate bunny_coord = validate_bunny_coord(true, Coordinate(row, column), player_coord);
                *bunny = new Bunny(bunny_coord, farm_dimensions);
            }
        }
    }
}

void BunnyManager::bunny_eat() const {
    if (bunny != nullptr) {
        farm->remove_plant( (*bunny)->position() );
    }
}

void BunnyManager::bunny_flee(Coordinate player_coord) const {
    if (bunny != nullptr) {
        (*bunny)->flee(player_coord);
    }
}

void BunnyManager::bunny_move(Coordinate player_coord) {
    if (bunny != nullptr) {
        (*bunny)->move();
        // Makes the bunny flee if it moves next to the player
        (*bunny)->flee(player_coord);
    } else {
        // Calls function to randomly spawn a Bunny
        spawn_bunny(player_coord);
    }
}

// If the bunny is out of bounds, delete the bunny
void BunnyManager::delete_bunny() {
    if ( bunny != nullptr && (*bunny)->is_out_of_bounds() ) {
        delete bunny;
        bunny = nullptr;
    }
}

BunnyManager::~BunnyManager() {
    if ( bunny != nullptr ) {
        delete bunny;
        bunny = nullptr;
    }
}