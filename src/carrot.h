#pragma once

#include <string>

#include "plot.h"

class Carrot : public Plot {
private:
    bool is_watered = false;
    int age = 0;

public:
    std::string symbol() override;
    void water() override;
    void end_day() override;
    ~Carrot() override = default;
};