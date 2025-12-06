#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/coordinate.h"
#include "../src/bunny.h"
#include "../src/bunny_manager.h"
#include "test_random.h"

TEST_CASE( "You can spawn a Bunny" ) {
    TestRandom random(4);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position().row_index == 0);
    REQUIRE( bunny->position().column_index == 0);
    // REQUIRE( bunny->position() == Coordinate(0,0) );
}