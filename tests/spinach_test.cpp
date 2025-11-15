#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.h"

TEST_CASE( "it returns a '-' as its symbol when planted" ) {
    Spinach spinach;
    REQUIRE( spinach.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 1 day" ) {
    Spinach spinach;
    spinach.end_day();
    REQUIRE( spinach.symbol() == "-" );
}

TEST_CASE( "it returns a '🌱' after 2 days" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 3 days" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 4 days" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌿' after 5 days" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌿" );
}

TEST_CASE( "It increases the age by 2 when we end the day after watering" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "Watering more than once per day has no effect" ) {
    Spinach spinach;
    spinach.water();
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "Watering on a given day should not effect future days" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "It ages the spinach properly after many waterings on many days" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "🌱" );
}

TEST_CASE( "is_grown() returns false if the spinach isn't in its mature state" ) {
    Spinach spinach;
    REQUIRE( !spinach.is_grown() );
    spinach.end_day();
    spinach.end_day();
    REQUIRE( !spinach.is_grown() );
}


TEST_CASE( "is_grown() returns true when the spinach is in its mature state" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.is_grown() );
}