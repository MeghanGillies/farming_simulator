#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "game.h"
#include "ansi_clear.hpp"
#include "carrot.h"
#include "lettuce.h"
#include "beet.h"
#include "brussel_sprouts.h"
#include "spinach.h"

// Printing Farm + Control Legend
void Game::pp() {
    ansi_clear();
    std::cout << std::right << std::setw(120) << "Current Day: " << farm.get_day_count() << std::endl;
    std::cout << printer.pp();
    std::cout << std::right << std::setw(118) << "Controls:"
              << "\n  W = up   A = left   S = down   D = right   X = water   H = harvest"
              << "\n  C = plant carrot   L = plant lettuce   P = plant spinach   B = plant beet"
              << "\n  N = plant brussel sprouts   E = end day   Q = quit\n";
}

// Do the following actions based on the Controls
void Game::user_action() {
    if (static_cast<char>(tolower(player_input)) == 'q') {
        game_in_progress = false;

    } else if (static_cast<char>(tolower(player_input)) == 'w') {
        player.move_up();
        b_manager.bunny_flee(player.position());

    } else if (static_cast<char>(tolower(player_input)) == 'a') {
        player.move_left();
        b_manager.bunny_flee(player.position());

    } else if (static_cast<char>(tolower(player_input)) == 's') {
        player.move_down();
        b_manager.bunny_flee(player.position());

    } else if (static_cast<char>(tolower(player_input)) == 'd') {
        player.move_right();
        b_manager.bunny_flee(player.position());

    } else if (static_cast<char>(tolower(player_input)) == 'c') {
        Carrot *carrot = new Carrot();
        farm.plant(player.position(), carrot);

    }  else if (static_cast<char>(tolower(player_input)) == 'l') {
        Lettuce *lettuce = new Lettuce();
        farm.plant(player.position(), lettuce);

    } else if (static_cast<char>(tolower(player_input)) == 'p') {
        Spinach *spinach = new Spinach();
        farm.plant(player.position(), spinach);

    } else if (static_cast<char>(tolower(player_input)) == 'b') {
        Beet *beet = new Beet();
        farm.plant(player.position(), beet);

    } else if (static_cast<char>(tolower(player_input)) == 'n') {
        Brussel_Sprouts *brussel_sprouts = new Brussel_Sprouts();
        farm.plant(player.position(), brussel_sprouts);

    } else if (static_cast<char>(tolower(player_input)) == 'x') {
        farm.water(player.position());

    } else if (static_cast<char>(tolower(player_input)) == 'h') {
        farm.harvest(player.position());

    } else if (static_cast<char>(tolower(player_input)) == 'e') {
        farm.end_day();

        // Bunny moves when day ends
        b_manager.bunny_move(player.position());
        // Will spawn a new bunny if bunny == nullptr
        b_manager.spawn_bunny(player.position());
    }
}


Game::Game() {
    srand( static_cast<unsigned int>(time(0)) ); // Seeding rand()
}

void Game::play() {
    while(game_in_progress) {
        if ( first_turn ) {
            // Calls function to randomly spawn a Bunny
            b_manager.spawn_bunny(player.position());
            first_turn = false;
        }

        // If the Bunny exists and is on the tile of a
        // vegetable, the vegetable gets eaten and is
        // removed from the farm
        b_manager.bunny_eat();

        // Printing Farm + Control Legend
        pp();

        // Get Player Input
        std::cin.get(player_input);
        std::cin.ignore(MAX, '\n');

        // Do the following actions based on the Controls
        user_action();

        // If the bunny is out of bounds, delete the bunny
        b_manager.delete_bunny();
    }
}