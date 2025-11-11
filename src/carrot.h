#pragma once

#include <string>

#include "plot.h"

class Carrot : public Plot {
private:
    const std::string baby = "🌱";
    const std::string grown = "🥕";
    bool is_watered = false;
    int age = 0;

public:
    std::string symbol() override;
    int get_age() const;
    void water();
    void end_day() override;
    ~Carrot() override = default;
};