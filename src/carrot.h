#pragma once

#include <string>
#include "vegetable.h"

class Carrot : public Vegetable {
private:
    bool is_watered = false;

    int age = 0;
    const int age_to_sprout = 1;
    const int age_to_grow = 2;

    const std::string tilled_soil = "-";
    const std::string baby = "🌱";
    const std::string grown = "🥕";

public:
    std::string symbol() override;
    void water() override;
    void end_day() override;
    bool is_grown() override;
    ~Carrot() override = default;
};