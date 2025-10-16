#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm.hpp"
#include "../src/carrot.h"

TEST_CASE( "It can be initialized with a single plot" ) {
    Farm farm(1,1);
    REQUIRE( farm.num_of_rows() == 1 );
    REQUIRE( farm.num_of_columns() == 1 );
}

TEST_CASE( "It can be initialized as a 1 x 2 farm" ) {
    Farm farm(1,2);
    REQUIRE( farm.num_of_rows() == 1 );
    REQUIRE( farm.num_of_columns() == 2 );
}

TEST_CASE( "It returns the symbol for a single soil plot" ) {
    Farm farm(1,1);
    REQUIRE( farm.get_symbol(0, 0) == "." );
}

TEST_CASE( "It returns the symbols for a 1 x 2 farm" ) {
    Farm farm(1,2);
    REQUIRE( farm.get_symbol(0, 0) == "." );
    REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "It returns the symbols for a 2 x 1 farm" ) {
    Farm farm(2,1);
    REQUIRE( farm.get_symbol(0, 0) == "." );
    REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "It returns the symbols for a 2 x 2 farm" ) {
    Farm farm(2,2);
    REQUIRE( farm.get_symbol(0, 0) == "." );
    REQUIRE( farm.get_symbol(0, 1) == "." );
    REQUIRE( farm.get_symbol(1, 0) == "." );
    REQUIRE( farm.get_symbol(1, 1) == "." );
}

TEST_CASE( "It allows us to plant a Carrot" ) {
    Farm farm(1,1);
    Carrot carrot;
    farm.plant(0, 0, &carrot);
    REQUIRE( farm.get_symbol(0, 0) == "🥕" );
}

TEST_CASE( "It allows us to harvest a Carrot" ) {
    Farm farm(1,1);
    Carrot carrot;
    farm.plant(0, 0, &carrot);
    REQUIRE( farm.get_symbol(0, 0) == "🥕" );
    farm.harvest(0,0);
    REQUIRE( farm.get_symbol(0, 0) == "." );
}

TEST_CASE( "Harvesting an empty plot does nothing." ) {
    Farm farm(1,1);
    REQUIRE( farm.get_symbol(0, 0) == "." );
    farm.harvest(0,0);
    REQUIRE( farm.get_symbol(0, 0) == "." );
}