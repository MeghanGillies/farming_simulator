#pragma once

#include <string>

#include "vegetable.h"

class Lettuce : public Vegetable {
private:
    bool is_watered = false;

    int age = 0;
    const int age_to_sprout = 2;
    const int age_to_grow = 4;

    const std::string tilled_soil = "-";
    const std::string baby = "🌱";
    const std::string grown = "🥬";

public:
    std::string symbol() override;
    void water() override;
    void end_day() override;
    bool is_grown() override;
    ~Lettuce() override = default;
};