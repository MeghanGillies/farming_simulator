#pragma once

#include <cstdlib>

#include "random.h"

class RealRandom: public Random {
public:
    int generate_int() override {
        return rand();
    }
};