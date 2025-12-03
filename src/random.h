#pragma once

class Random {
public:
    virtual int generate_int() = 0;
    virtual ~Random() = default;
};