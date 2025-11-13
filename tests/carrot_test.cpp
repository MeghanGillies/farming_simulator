#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/carrot.h"

TEST_CASE( "it returns a '-' as its symbol when planted" ) {
    Carrot carrot;
    REQUIRE( carrot.symbol() == "-" );
}

TEST_CASE( "it returns a '🌱' after 1 day" ) {
    Carrot carrot;
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🥕' after 2 days" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
}

TEST_CASE( "It increases the age by 2 when we end the day after watering" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
}

TEST_CASE( "Watering more than once per day has no effect" ) {
    Carrot carrot;
    carrot.water();
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
}

TEST_CASE( "Watering on a given day should not effect future days" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
}

TEST_CASE( "It ages the carrot properly after many waterings on many days" ) {
    Carrot carrot;
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
    carrot.water();
    carrot.end_day();
    REQUIRE( carrot.symbol() == "🥕" );
}

TEST_CASE( "is_grown() returns false if the carrot isn't in its mature state" ) {
    Carrot carrot;
    REQUIRE( !carrot.is_grown() );
    carrot.end_day();
    REQUIRE( !carrot.is_grown() );
}


TEST_CASE( "is_grown() returns true when the carrot is in its mature state" ) {
    Carrot carrot;
    carrot.end_day();
    carrot.end_day();
    REQUIRE( carrot.is_grown() );
}