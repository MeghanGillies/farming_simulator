#pragma once

#include <string>

#include "farm.hpp"

class FarmPrinter {
private:
    Farm *farm;
public:
    FarmPrinter(Farm *f);
    std::string pp();
};