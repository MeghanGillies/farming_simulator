#pragma once

#include <string>

#include "plot.h"

class Carrot : public Plot {
private:
    const std::string baby = "🌱";
    const std::string grown = "🥕";
    int age = 0;

public:
    std::string symbol() override;
    void end_day() override;
    ~Carrot() override = default;
};