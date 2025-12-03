#pragma once

#include <string>

#include "bunny.h"
#include "farm.hpp"
#include "player.h"

class FarmPrinter {
private:
    Farm *farm;
    Player *player;
    Bunny **bunny;
public:
    FarmPrinter(Farm *f, Player *p, Bunny **b);
    std::string pp();
};