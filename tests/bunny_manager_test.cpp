#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/coordinate.h"
#include "../src/bunny.h"
#include "../src/bunny_manager.h"
#include "test_random.h"
#include "../src/carrot.h"

TEST_CASE( "You can spawn a Bunny on the TOP edge" ) {
    int arr[3] = {4,4,15};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(0,3) );
}

TEST_CASE( "You can spawn a Bunny on the BOTTOM edge" ) {
    int arr[3] = {4,5,6};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(3,2) );
}

TEST_CASE( "You can spawn a Bunny on the LEFT edge" ) {
    int arr[3] = {4,6,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(1,0) );
}

TEST_CASE( "You can spawn a Bunny on the RIGHT edge" ) {
    int arr[3] = {4,7,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(1,3) );
}

TEST_CASE( "If the bunny spawns on the TOP edge, it will move DOWN" ) {
    int arr[3] = {4,4,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(0,1) );

    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,1) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(2,1) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(3,1) );
}

TEST_CASE( "If the bunny spawns on the BOTTOM edge, it will move UP" ) {
    int arr[3] = {4,5,6};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(3,2) );

    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(2,2) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,2) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(0,2) );
}

TEST_CASE( "If the bunny spawns on the LEFT edge, it will move RIGHT" ) {
    int arr[3] = {4,6,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(1,0) );

    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,1) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,2) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,3) );
}

TEST_CASE( "If the bunny spawns on the RIGHT edge, it will move LEFT" ) {
    int arr[3] = {4,7,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(1,3) );

    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,2) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,1) );
    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,0) );
}

TEST_CASE( "If the bunny is on a vegetable, the bunny will eat it." ) {
    int arr[3] = {4,4,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Carrot *carrot = new Carrot();
    farm.plant(Coordinate(1,1), carrot );

    Coordinate player_position(3,3);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(0,1) );
    REQUIRE( farm.get_symbol(Coordinate(1, 1) ) == "-" );

    b_manager.bunny_move(player_position);
    REQUIRE( bunny->position() == Coordinate(1,1) );
    b_manager.bunny_eat();
    REQUIRE( farm.get_symbol(Coordinate(1, 1) ) == "." );
}

TEST_CASE( "The bunny will flee in the opposite direction of the player." ) {
    int arr[3] = {4,4,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(0,0);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(0,1) );
    b_manager.bunny_flee(player_position);
    REQUIRE( bunny->position() == Coordinate(0,5) );
}

TEST_CASE( "If the bunny is out of bounds, then it will delete the bunny" ) {
    int arr[3] = {4,4,5};
    TestRandom random(arr);
    FarmDimensions dimensions(4,4);
    Farm farm(&dimensions);
    Bunny* bunny = nullptr;
    BunnyManager b_manager(&bunny, &dimensions, &farm, &random);

    Coordinate player_position(0,0);
    b_manager.spawn_bunny(player_position);

    REQUIRE( bunny != nullptr );
    REQUIRE( bunny->position() == Coordinate(0,1) );
    b_manager.bunny_flee(player_position);
    REQUIRE( bunny->position() == Coordinate(0,5) );

    b_manager.delete_bunny();
    REQUIRE( bunny == nullptr );
}