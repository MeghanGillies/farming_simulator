#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm.hpp"
#include "../src/farm_printer.h"

TEST_CASE( "Pretty Prints a single plot of land" ) {
    Farm farm(1,1);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == ".\t\n" );
}

TEST_CASE( "Pretty Prints a 1 x 2 farm" ) {
    Farm farm(1,2);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == ".\t.\t\n" );
}

TEST_CASE( "Pretty Prints a 2 x 1 farm" ) {
    Farm farm(2,1);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == ".\t\n.\t\n" );
}

TEST_CASE( "Pretty Prints a 2 x 2 farm" ) {
    Farm farm(2,2);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == ".\t.\t\n.\t.\t\n" );
}