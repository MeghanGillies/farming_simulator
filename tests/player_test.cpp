#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.h"
#include "../src/farm_dimensions.h"

TEST_CASE( "It starts the player at (0,0)" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "It moves the player to the right, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_right();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 1 );
}

TEST_CASE( "It moves the player to the left, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_right();
    player.move_right();
    player.move_left();
    REQUIRE( player.row() == 0 );
    REQUIRE( player.column() == 1 );
}

TEST_CASE( "It moves the player up, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_down();
    player.move_down();
    player.move_up();
    REQUIRE( player.row() == 1 );
    REQUIRE( player.column() == 0 );
}

TEST_CASE( "It moves the player down, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_down();
    REQUIRE( player.row() == 1 );
    REQUIRE( player.column() == 0 );
}