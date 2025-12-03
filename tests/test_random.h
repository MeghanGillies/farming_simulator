#pragma once

#include "../src/random.h"

class TestRandom: public Random {
private:
    int num;
public:
    explicit TestRandom( int x ) : num( x ) {}

    int generate_int() override {
        return num;
    }
};