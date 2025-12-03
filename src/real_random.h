#pragma once

#include <cstdlib>

#include "random.h"

class TestRandom: public Random {
public:
    override int generate_int() {
        return rand();
    }
};