#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm_printer.h"
#include "../src/farm_dimensions.h"
#include "../src/farm.hpp"
#include "../src/player.h"
#include "../src/bunny.h"

TEST_CASE( "Pretty Prints a single plot of land" ) {
    FarmDimensions dimensions(1,1);
    Farm farm(&dimensions);
    Player player(&dimensions);
    Bunny *bunny = nullptr;

    FarmPrinter printer(&farm, &player, bunny);
    REQUIRE( printer.pp() == "\n  🧑‍🌾\t\n\n" );
}

TEST_CASE( "Pretty Prints a 1 x 2 farm" ) {
    FarmDimensions dimensions(1,2);
    Farm farm(&dimensions);
    Player player(&dimensions);
    Bunny *bunny = nullptr;

    FarmPrinter printer(&farm, &player, bunny);
    REQUIRE( printer.pp() == "\n  🧑‍🌾\t  .\t\n\n" );
}

TEST_CASE( "Pretty Prints a 2 x 1 farm" ) {
    FarmDimensions dimensions(2,1);
    Farm farm(&dimensions);
    Player player(&dimensions);
    Bunny *bunny = nullptr;

    FarmPrinter printer(&farm, &player, bunny);
    REQUIRE( printer.pp() == "\n  🧑‍🌾\t\n\n  .\t\n\n" );
}

TEST_CASE( "Pretty Prints a 2 x 2 farm" ) {
    FarmDimensions dimensions(2,2);
    Farm farm(&dimensions);
    Player player(&dimensions);
    Bunny *bunny = nullptr;

    FarmPrinter printer(&farm, &player, bunny);
    REQUIRE( printer.pp() == "\n  🧑‍🌾\t  .\t\n\n  .\t  .\t\n\n" );
}

// Testing if the Bunny will be printed
TEST_CASE( "Will Pretty Print a Farm with a Bunny at its current position" ) {
    FarmDimensions dimensions(2,2);
    Farm farm(&dimensions);
    Player player(&dimensions);
    Bunny *bunny = new Bunny(Coordinate(1,1), &dimensions);

    FarmPrinter printer(&farm, &player, bunny);
    REQUIRE( printer.pp() == "\n  🧑‍🌾\t  .\t\n\n  .\t  🐇\t\n\n" );

    delete bunny;
    bunny = nullptr;
}