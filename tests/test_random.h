#pragma once

#include "../src/random.h"

class TestRandom: public Random {
private:
    static constexpr int SIZE = 3;
    int array[SIZE];
    int counter = 0;
public:
    explicit TestRandom( int arr[] ) {
        for (int i = 0; i < SIZE; i++) {
            array[i] = arr[i];
        }
    }

    int generate_int() override {
        int value = array[counter];
        counter++;
        return value;
    }
};