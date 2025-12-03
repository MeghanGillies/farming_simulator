#pragma once

#include <cstdlib>

#include "random.h"

class TestRandom: public Random {
public:
    int generate_int() override {
        return rand();
    }
};