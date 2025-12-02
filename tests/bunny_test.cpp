#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/coordinate.h"
#include "../src/bunny.h"

TEST_CASE( "You can create a Bunny with a given starting position." ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,0), &dimensions);
    REQUIRE( bunny.position() == Coordinate(0,0) );
}

TEST_CASE( "Bunny will return '🐇' as its symbol" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,0), &dimensions);
    REQUIRE( bunny.symbol() == "🐇" );
}


// Testing move()
TEST_CASE( "If the Bunny starts on the TOP edge of the farm, it will move DOWN." ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,2), &dimensions);
    REQUIRE( bunny.position() == Coordinate(0,2) );

    bunny.move();
    REQUIRE( bunny.position() == Coordinate(1,2) );
}

TEST_CASE( "If the Bunny starts on the BOTTOM edge of the farm, it will move UP." ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(3,1), &dimensions);
    REQUIRE( bunny.position() == Coordinate(3,1) );

    bunny.move();
    REQUIRE( bunny.position() == Coordinate(2,1) );
}

TEST_CASE( "If the Bunny starts on the LEFT edge of the farm, it will move RIGHT." ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(1,0), &dimensions);
    REQUIRE( bunny.position() == Coordinate(1,0) );

    bunny.move();
    REQUIRE( bunny.position() == Coordinate(1,1) );
}

TEST_CASE( "If the Bunny starts on the RIGHT edge of the farm, it will move DOWN." ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(1,3), &dimensions);
    REQUIRE( bunny.position() == Coordinate(1,3) );

    bunny.move();
    REQUIRE( bunny.position() == Coordinate(1,2) );
}


// Testing flee()
TEST_CASE( "If the Player is not next to the Bunny, nothing happens" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,0), &dimensions);
    REQUIRE( bunny.position() == Coordinate(0,0) );

    bunny.flee(Coordinate(3, 2));
    REQUIRE( bunny.position() == Coordinate(0,0) );
}

TEST_CASE( "If the Player is ABOVE the Bunny, It flees DOWN 4 spaces" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(1,1), &dimensions);
    REQUIRE( bunny.position() == Coordinate(1,1) );

    bunny.flee(Coordinate(0, 1));
    REQUIRE( bunny.position() == Coordinate(5,1) );
}

TEST_CASE( "If the Player is BELOW the Bunny, It flees UP 4 spaces" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(1,1), &dimensions);
    REQUIRE( bunny.position() == Coordinate(1,1) );

    bunny.flee(Coordinate(2, 1));
    REQUIRE( bunny.position() == Coordinate(-3,1) );
}

TEST_CASE( "If the Player is to the RIGHT of the Bunny, It flees LEFT 4 spaces" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(1,1), &dimensions);
    REQUIRE( bunny.position() == Coordinate(1,1) );

    bunny.flee(Coordinate(1, 2));
    REQUIRE( bunny.position() == Coordinate(1,-3 ) );
}

TEST_CASE( "If the Player is to the LEFT of the Bunny, It flees RIGHT 4 spaces" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(1,1), &dimensions);
    REQUIRE( bunny.position() == Coordinate(1,1) );

    bunny.flee(Coordinate(1, 0));
    REQUIRE( bunny.position() == Coordinate(1,5) );
}

// Testing when the Bunny is Out of Bounds
TEST_CASE( "Will return false if Bunny is in the bounds of the farm" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,0), &dimensions);
    REQUIRE( !bunny.is_out_of_bounds() );
}

TEST_CASE( "Will return true if Bunny is out of bounds UP" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(-1,0), &dimensions);
    REQUIRE( bunny.is_out_of_bounds() );
}

TEST_CASE( "Will return true if Bunny is out of bounds LEFT" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,-1), &dimensions);
    REQUIRE( bunny.is_out_of_bounds() );
}

TEST_CASE( "Will return true if Bunny is out of bounds DOWN" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(4,0), &dimensions);
    REQUIRE( bunny.is_out_of_bounds() );
}

TEST_CASE( "Will return true if Bunny is out of bounds RIGHT" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(0,4), &dimensions);
    REQUIRE( bunny.is_out_of_bounds() );
}

TEST_CASE( "Will return true if Bunny is somewhere out of bounds of the farm" ) {
    FarmDimensions dimensions(4,4);
    Bunny bunny(Coordinate(-3,2), &dimensions);
    REQUIRE( bunny.is_out_of_bounds() );
}