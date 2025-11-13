#pragma once

#include <string>

#include "vegetable.h"

class Carrot : public Vegetable {
private:
    bool is_watered = false;
    int age = 0;

public:
    std::string symbol() override;
    void water() override;
    void end_day() override;
    ~Carrot() override = default;
};