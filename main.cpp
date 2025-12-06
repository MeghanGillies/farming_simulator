#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#include "src/farm_dimensions.h"
#include "src/farm.hpp"
#include "src/farm_printer.h"
#include "src/carrot.h"
#include "src/lettuce.h"
#include "src/player.h"
#include "src/ansi_clear.hpp"
#include "src/beet.h"
#include "src/brussel_sprouts.h"
#include "src/spinach.h"
#include "src/bunny.h"

int main() {
    srand( static_cast<unsigned int>(time(0)) ); // Seeding rand()
    constexpr std::streamsize MAX{std::numeric_limits<std::streamsize>::max()}; // Max for cin.ignore

    FarmDimensions dimensions(5,8);
    Player player(&dimensions);
    Farm farm(&dimensions);
    Bunny *bunny = nullptr;
    FarmPrinter printer(&farm, &player, &bunny);
    bool game_in_progress = true;
    bool first_turn = true;
    char player_input;

    while(game_in_progress) {
        if ( first_turn ) {
            // Calls function to randomly spawn a Bunny
            spawn_bunny(&bunny, dimensions, player.position());
            first_turn = false;
        }

        // If the Bunny exists and is on the tile of a
        // vegetable, the vegetable gets eaten and is
        // removed from the farm (aka harvested)
        if (bunny != nullptr) {
            farm.harvest(bunny->position());
        }

        // Printing Farm + Control Legend
        // ansi_clear();
        std::cout << std::right << std::setw(120) << "Current Day: " << farm.get_day_count() << std::endl;
        std::cout << printer.pp();
        std::cout << std::right << std::setw(118) << "Controls:"
                  << "\n  W = up   A = left   S = down   D = right   X = water   H = harvest"
                  << "\n  C = plant carrot   L = plant lettuce   P = plant spinach   B = plant beet"
                  << "\n  N = plant brussel sprouts   E = end day   Q = quit\n";

        // Get Player Input
        std::cin.get(player_input);
        std::cin.ignore(MAX, '\n');

        // Do the following actions based on the Controls
        if (static_cast<char>(tolower(player_input)) == 'q') {
            game_in_progress = false;

        } else if (static_cast<char>(tolower(player_input)) == 'w') {
            player.move_up();

            // Bunny will flee if Player is next to it
            if (bunny != nullptr) {
                bunny->flee(player.position());
            }

        } else if (static_cast<char>(tolower(player_input)) == 'a') {
            player.move_left();

            // Bunny will flee if Player is next to it
            if (bunny != nullptr) {
                bunny->flee(player.position());
            }

        } else if (static_cast<char>(tolower(player_input)) == 's') {
            player.move_down();

            // Bunny will flee if Player is next to it
            if (bunny != nullptr) {
                bunny->flee(player.position());
            }

        } else if (static_cast<char>(tolower(player_input)) == 'd') {
            player.move_right();

            // Bunny will flee if Player is next to it
            if (bunny != nullptr) {
                bunny->flee(player.position());
            }

        } else if (static_cast<char>(tolower(player_input)) == 'c') {
            Carrot *carrot = new Carrot();
            farm.plant(player.position(), carrot);

        } else if (static_cast<char>(tolower(player_input)) == 'h') {
            farm.harvest(player.position());

        } else if (static_cast<char>(tolower(player_input)) == 'e') {
            farm.end_day();

            // Bunny moves when day ends
            if (bunny != nullptr) {
                bunny->move();
                bunny->flee(player.position());
            } else {
                // Calls function to randomly spawn a Bunny
                spawn_bunny(&bunny, dimensions, player.position());
            }

        } else if (static_cast<char>(tolower(player_input)) == 'x') {
            farm.water(player.position());

        } else if (static_cast<char>(tolower(player_input)) == 'l') {
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
        }

        // If the bunny is out of bounds, delete the bunny
        if ( bunny != nullptr && bunny->is_out_of_bounds() ) {
            delete bunny;
            bunny = nullptr;
        }
    }

    return 0;
}