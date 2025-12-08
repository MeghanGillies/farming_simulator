#pragma once

#include "farm_dimensions.h"
#include "farm.hpp"
#include "farm_printer.h"
#include "player.h"
#include "bunny.h"
#include "bunny_manager.h"
#include "real_random.h"

class Game {
private:
    static constexpr std::streamsize MAX{std::numeric_limits<std::streamsize>::max()}; // Max for cin.ignore

    FarmDimensions dimensions = FarmDimensions(5,8);
    Player player = Player(&dimensions);
    Farm farm = Farm(&dimensions);
    Bunny *bunny = nullptr;
    RealRandom random;
    BunnyManager b_manager = BunnyManager(&bunny, &dimensions, &farm, &random);
    FarmPrinter printer = FarmPrinter(&farm, &player, &bunny);

    bool game_in_progress = true;
    bool first_turn = true;
    char player_input = ' ';

    void pp();
    void user_action();

public:
    Game();
    void play();
};
