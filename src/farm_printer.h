#pragma once

#include <string>

#include "farm.hpp"
#include "player.h"

class FarmPrinter {
private:
    Farm *farm;
    Player *player;
public:
    FarmPrinter(Farm *f, Player *p);
    std::string pp();
};