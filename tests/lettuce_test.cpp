#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.h"

TEST_CASE( "it returns a '-' as its symbol when planted" ) {
    Lettuce lettuce;
    REQUIRE( lettuce.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 1 day" ) {
    Lettuce lettuce;
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "-" );
}

TEST_CASE( "it returns a '🌱' after 2 days" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 3 days" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🥬' after 4 days" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🥬" );
}


TEST_CASE( "It increases the age by 2 when we end the day after watering" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
}

TEST_CASE( "Watering more than once per day has no effect" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
}

TEST_CASE( "Watering on a given day should not effect future days" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
}

TEST_CASE( "It ages the lettuce properly after many waterings on many days" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🌱" );
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "🥬" );
}

TEST_CASE( "is_grown() returns false if the lettuce isn't in its mature state" ) {
    Lettuce lettuce;
    REQUIRE( !lettuce.is_grown() );
    lettuce.end_day();
    REQUIRE( !lettuce.is_grown() );
    lettuce.end_day();
    REQUIRE( !lettuce.is_grown() );
    lettuce.end_day();
    REQUIRE( !lettuce.is_grown() );
}


TEST_CASE( "is_grown() returns true when the lettuce is in its mature state" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.is_grown() );
}