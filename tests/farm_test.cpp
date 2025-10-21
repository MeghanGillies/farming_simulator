#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm.hpp"
#include "../src/soil.h"
#include "../src/carrot.h"
#include "../src/coordinate.h"

TEST_CASE( "It can be initialized with a single plot" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    REQUIRE( farm.num_of_rows() == 1 );
    REQUIRE( farm.num_of_columns() == 1 );
}

TEST_CASE( "It can be initialized as a 1 x 2 farm" ) {
    FarmDimensions dimensions(1,2);
    Farm farm(&dimensions);
    REQUIRE( farm.num_of_rows() == 1 );
    REQUIRE( farm.num_of_columns() == 2 );
}

TEST_CASE( "It returns the symbol for a single soil plot" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
}

TEST_CASE( "It returns the symbols for a 1 x 2 farm" ) {
    FarmDimensions dimensions(1,2);
    Farm farm(&dimensions);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
    REQUIRE( farm.get_symbol(Coordinate(0,1)) == "." );
}

TEST_CASE( "It returns the symbols for a 2 x 1 farm" ) {
    FarmDimensions dimensions(2,1);
    Farm farm(&dimensions);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
    REQUIRE( farm.get_symbol(Coordinate(1,0)) == "." );
}

TEST_CASE( "It returns the symbols for a 2 x 2 farm" ) {
    FarmDimensions dimensions(2,2);
    Farm farm(&dimensions);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
    REQUIRE( farm.get_symbol(Coordinate(0,1)) == "." );
    REQUIRE( farm.get_symbol(Coordinate(1,0)) == "." );
    REQUIRE( farm.get_symbol(Coordinate(1,1)) == "." );
}

TEST_CASE( "It allows us to plant a Carrot" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    Carrot *carrot = new Carrot();
    farm.plant(Coordinate(0,0), carrot);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🌱" );
}

TEST_CASE( "When ending the day, the Carrots will grow." ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    Carrot *carrot = new Carrot();
    farm.plant(Coordinate(0,0), carrot);

    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🌱" );
    farm.end_day();
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🥕" );
}

TEST_CASE( "The day_count is initialized at 1" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    REQUIRE( farm.get_day_count() == 1 );
}

TEST_CASE( "The day_count will increment when the day ends" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    farm.end_day();
    REQUIRE( farm.get_day_count() == 2 );
}

TEST_CASE( "You cannot plant a carrot where there is already a carrot" ) {
    FarmDimensions dimensions(1,2);
    Farm farm(&dimensions);

    Carrot *carrot1 = new Carrot();
    farm.plant(Coordinate(0,0), carrot1);
    farm.end_day();
    Carrot *carrot2 = new Carrot();
    farm.plant(Coordinate(0,1), carrot2);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🥕" );
    REQUIRE( farm.get_symbol(Coordinate(0,1)) == "🌱" );

    Carrot *carrot3 = new Carrot();
    Carrot *carrot4 = new Carrot();
    farm.plant(Coordinate(0,0), carrot3);
    farm.plant(Coordinate(0,1), carrot4);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🥕" );
    REQUIRE( farm.get_symbol(Coordinate(0,1)) == "🌱" );

    delete carrot3;
    delete carrot4;
}

TEST_CASE( "It allows us to harvest a Carrot" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    Carrot *carrot = new Carrot();
    farm.plant(Coordinate(0,0), carrot);

    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🌱" );
    farm.end_day();
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🥕" );
    farm.harvest(Coordinate(0,0));
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
}

TEST_CASE( "Harvesting an empty plot does nothing." ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
    farm.harvest(Coordinate(0,0));
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "." );
}

TEST_CASE( "Harvesting a sprout does nothing" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    Carrot *carrot = new Carrot();
    farm.plant(Coordinate(0,0), carrot);

    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🌱" );
    farm.harvest(Coordinate(0,0));
    REQUIRE( farm.get_symbol(Coordinate(0,0)) == "🌱" );
}