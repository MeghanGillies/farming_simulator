#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/beet.h"

TEST_CASE( "it returns a '-' as its symbol when planted" ) {
    Beet beet;
    REQUIRE( beet.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 1 day" ) {
    Beet beet;
    beet.end_day();
    REQUIRE( beet.symbol() == "-" );
}

TEST_CASE( "it returns a '🌱' after 2 days" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 3 days" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 4 days" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 5 days" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 6 days" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🫜' after 7 days" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.symbol() == "🫜" );
}

TEST_CASE( "It increases the age by 2 when we end the day after watering" ) {
    Beet beet;
    beet.water();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "Watering more than once per day has no effect" ) {
    Beet beet;
    beet.water();
    beet.water();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "Watering on a given day should not effect future days" ) {
    Beet beet;
    beet.water();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
}

TEST_CASE( "It ages the beet properly after many waterings on many days" ) {
    Beet beet;
    beet.water();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
    beet.water();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
    beet.water();
    beet.end_day();
    REQUIRE( beet.symbol() == "🌱" );
    beet.end_day();
    REQUIRE( beet.symbol() == "🫜" );
}

TEST_CASE( "is_grown() returns false if the beet isn't in its mature state" ) {
    Beet beet;
    REQUIRE( !beet.is_grown() );
    beet.end_day();
    REQUIRE( !beet.is_grown() );
}


TEST_CASE( "is_grown() returns true when the beet is in its mature state" ) {
    Beet beet;
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    beet.end_day();
    REQUIRE( beet.is_grown() );
}