#include <iostream>
#include <iomanip>

#include "src/farm_dimensions.h"
#include "src/farm.hpp"
#include "src/farm_printer.h"
#include "src/carrot.h"
#include "src/lettuce.h"
#include "src/player.h"
#include "src/ansi_clear.hpp"

int main() {
    constexpr std::streamsize MAX{std::numeric_limits<std::streamsize>::max()}; // Max for cin.ignore

    FarmDimensions dimensions(5,8);
    Player player(&dimensions);
    Farm farm(&dimensions);
    FarmPrinter printer(&farm, &player);
    bool game_in_progress = true;
    char player_input;

    while(game_in_progress) {
        ansi_clear();
        std::cout << std::right << std::setw(120) << "Current Day: " << farm.get_day_count() << std::endl;
        std::cout << printer.pp();
        std::cout << std::right << std::setw(118) << "Controls:"
                  << "\n  W = up   A = left   S = down   D = right   X = water   H = harvest"
                  << "\n  C = plant carrot   L = plant lettuce   P = plant spinach   B = plant beet"
                  << "\n  N = plant brussel sprouts   E = end day   Q = quit\n";
        std::cin.get(player_input);
        std::cin.ignore(MAX, '\n');

        if (static_cast<char>(tolower(player_input)) == 'q') {
            game_in_progress = false;

        } else if (static_cast<char>(tolower(player_input)) == 'w') {
            player.move_up();

        } else if (static_cast<char>(tolower(player_input)) == 'a') {
            player.move_left();

        } else if (static_cast<char>(tolower(player_input)) == 's') {
            player.move_down();

        } else if (static_cast<char>(tolower(player_input)) == 'd') {
            player.move_right();

        } else if (static_cast<char>(tolower(player_input)) == 'c') {
            Carrot *carrot = new Carrot();
            farm.plant(player.position(), carrot);

        } else if (static_cast<char>(tolower(player_input)) == 'h') {
            farm.harvest(player.position());

        } else if (static_cast<char>(tolower(player_input)) == 'e') {
            farm.end_day();

        } else if (static_cast<char>(tolower(player_input)) == 'x') {
            farm.water(player.position());

        } else if (static_cast<char>(tolower(player_input)) == 'l') {
            Lettuce *lettuce = new Lettuce();
            farm.plant(player.position(), lettuce);
        }
    }

    return 0;
}