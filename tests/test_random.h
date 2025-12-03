#pragma once

#include "../src/random.h"

class TestRandom: public Random {
private:
    int num;
public:
    explicit TestRandom( int x ) : num( x ) {}

    override int generate_int() const {
        return num;
    }
};