#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.h"

TEST_CASE( "it returns a '🌱' as its symbol when planted" ) {
    Carrot carrot;
    REQUIRE( carrot.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🥕' when it is grown" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
}