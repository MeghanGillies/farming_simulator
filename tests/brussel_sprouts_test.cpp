#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brussel_sprouts.h"

TEST_CASE( "it returns a '-' as its symbol when planted" ) {
    Brussel_Sprouts brussel_sprouts;
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 1 day" ) {
    Brussel_Sprouts brussel_sprouts;
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 2 days" ) {
    Brussel_Sprouts brussel_sprouts;
    brussel_sprouts.end_day();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 3 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 3; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "it returns a '-' after 4 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 4; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "it returns a '🌱' after 5 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 5; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 6 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 6; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 7 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 7; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 8 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 8; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 9 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 9; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 10 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 10; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 11 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 11; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 12 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 12; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 13 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 13; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌱' after 14 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 14; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
}

TEST_CASE( "it returns a '🌳' after 15 days" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 15; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.symbol() == "🌳" );
}

TEST_CASE( "It increases the age by 2 when we end the day after watering" ) {
    Brussel_Sprouts brussel_sprouts;
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "Watering more than once per day has no effect" ) {
    Brussel_Sprouts brussel_sprouts;
    brussel_sprouts.water();
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "Watering on a given day should not effect future days" ) {
    Brussel_Sprouts brussel_sprouts;
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
}

TEST_CASE( "It ages the brussel_sprouts properly after many waterings on many days" ) {
    Brussel_Sprouts brussel_sprouts;
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "-" );
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
    brussel_sprouts.water();
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "🌱" );
    brussel_sprouts.end_day();
    REQUIRE( brussel_sprouts.symbol() == "🌳" );
}

TEST_CASE( "is_grown() returns false if the brussel_sprouts isn't in its mature state" ) {
    Brussel_Sprouts brussel_sprouts;
    REQUIRE( !brussel_sprouts.is_grown() );
    brussel_sprouts.end_day();
    REQUIRE( !brussel_sprouts.is_grown() );
}


TEST_CASE( "is_grown() returns true when the brussel_sprouts is in its mature state" ) {
    Brussel_Sprouts brussel_sprouts;
    for (int i = 0; i < 15; i++) {
        brussel_sprouts.end_day();
    }
    REQUIRE( brussel_sprouts.is_grown() );
}