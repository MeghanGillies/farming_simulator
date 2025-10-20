#pragma once

#include <string>

#include "plot.h"

class Carrot : public Plot {
private:
    const std::string baby = "🌱";
    const std::string grown = "🥕";
    std::string current_symbol;
public:
    Carrot();
    std::string symbol() override;
    ~Carrot() override = default;
};