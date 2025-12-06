#pragma once

#include "coordinate.h"
#include "farm_dimensions.h"
#include "farm.hpp"
#include "bunny.h"
#include "random.h"

class BunnyManager {
private:
    Bunny **bunny;
    FarmDimensions *farm_dimensions;
    Farm *farm;
    Random *random;

    Coordinate validate_bunny_coord( bool row_is_rand, Coordinate bunny_coord, Coordinate player_coord ) const;

public:
    // Constructor
    BunnyManager(Bunny **b, FarmDimensions *dimensions, Farm *f , Random *r);

    // Destructor
    ~BunnyManager();

    void spawn_bunny(Coordinate player_coord);
    void bunny_eat() const;
    void bunny_flee(Coordinate player_coord) const;
    void bunny_move(Coordinate player_coord);
    void delete_bunny();
};
