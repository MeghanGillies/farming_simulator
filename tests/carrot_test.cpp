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

TEST_CASE( "When planting a carrot, age returns 1" ) {
    Carrot carrot;
    REQUIRE( carrot.get_age() == 0 );
}

TEST_CASE( "Has age 1 when ending the day once" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.get_age() == 1 );
}

TEST_CASE( "Has age 2 when ending the day twice" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "It increases the age by 2 when we end the day after watering" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "Watering more than once per day has no effect" ) {
    Carrot carrot;
    carrot.water();
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 2 );
}

TEST_CASE( "Watering on a given day should not effect future days" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 3 );
}

TEST_CASE( "It ages the carrot properly after many waterings on many days" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.get_age() == 4 );
}