#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.h"
#include "../src/farm_dimensions.h"
#include "../src/coordinate.h"

TEST_CASE( "It starts the player at (0,0)" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    REQUIRE( player.position() == Coordinate(0, 0) );
}

TEST_CASE( "It moves the player to the right, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_right();
    REQUIRE( player.position() == Coordinate(0, 1) );
}

TEST_CASE( "It moves the player to the left, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_right();
    player.move_right();
    player.move_left();
    REQUIRE( player.position() == Coordinate(0, 1) );
}

TEST_CASE( "It moves the player up, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_down();
    player.move_down();
    player.move_up();
    REQUIRE( player.position() == Coordinate(1, 0) );
}

TEST_CASE( "It moves the player down, when not at edge" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);
    player.move_down();
    REQUIRE( player.position() == Coordinate(1, 0) );
}

TEST_CASE( "When the player reaches the edge, it stops moving" ) {
    FarmDimensions dimensions(3,3);
    Player player(&dimensions);

    // Moving Up
    player.move_up(); // would move it out of bounds
    REQUIRE( player.position() == Coordinate(0,0) );

    // Moving Down
    player.move_down();
    player.move_down();
    player.move_down(); // would move it out of bounds
    REQUIRE( player.position() == Coordinate(2, 0) );

    // Moving Left
    player.move_left(); // would move it out of bounds
    REQUIRE( player.position() == Coordinate(2, 0) );

    // Moving Right
    player.move_right();
    player.move_right();
    player.move_right(); // would move it out of bounds
    REQUIRE( player.position() == Coordinate(2, 2) );
}