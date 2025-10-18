#include <iostream>

#include "src/farm_dimensions.h"
#include "src/farm.hpp"
#include "src/farm_printer.h"
#include "src/carrot.h"
#include "src/player.h"
#include "src/ansi_clear.hpp"

int main() {
    FarmDimensions dimensions(5,8);
    Player player(&dimensions);
    Farm farm(&dimensions);
    FarmPrinter printer(&farm, &player);
    bool game_in_progress = true;
    std::string player_input;

    while(game_in_progress) {
        ansi_clear();
        std::cout << printer.pp() << std::endl;
        std::cout << "Controls:\tW = up, A = left, S = down, D = right,"
                  << "\n\t\t\tC = plant Carrot, H = harvest, Q = quit\n";
        std::cin >> player_input;

        if (player_input == "q") {
            game_in_progress = false;

        } else if (player_input == "w") {
            player.move_up();

        } else if (player_input == "a") {
            player.move_left();

        } else if (player_input == "s") {
            player.move_down();

        } else if (player_input == "d") {
            player.move_right();

        } else if (player_input == "c") {
            Carrot *carrot = new Carrot();
            farm.plant(player.position(), carrot);

        } else if (player_input == "h") {
            farm.harvest(player.position());
        }
    }

    return 0;
}
