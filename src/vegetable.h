#pragma once

#include <string>

class Vegetable {
public:
    virtual std::string symbol() = 0;
    virtual void water() = 0;
    virtual void end_day() = 0;
    virtual ~Vegetable() = default;
};