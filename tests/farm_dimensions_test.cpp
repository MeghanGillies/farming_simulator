#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/farm_dimensions.h"

#include "catch2/matchers/catch_matchers.hpp"

TEST_CASE("Can get the number of rows + columns for a 1 x 1 farm") {
    FarmDimensions dimensions(1,1);
    REQUIRE(dimensions.get_num_rows() == 1);
    REQUIRE(dimensions.get_num_columns() == 1);
}

TEST_CASE("Can get the number of rows + columns for a 1 x 2 farm") {
    FarmDimensions dimensions(1,2);
    REQUIRE(dimensions.get_num_rows() == 1);
    REQUIRE(dimensions.get_num_columns() == 2);
}

TEST_CASE("Can get the number of rows + columns for a 2 x 2 farm") {
    FarmDimensions dimensions(2,2);
    REQUIRE(dimensions.get_num_rows() == 2);
    REQUIRE(dimensions.get_num_columns() == 2);
}

TEST_CASE("Can get the number of rows + columns for a 7 x 8 farm") {
    FarmDimensions dimensions(7,8);
    REQUIRE(dimensions.get_num_rows() == 7);
    REQUIRE(dimensions.get_num_columns() == 8);
}