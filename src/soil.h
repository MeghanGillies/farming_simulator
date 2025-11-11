#pragma once

#include <string>

#include "plot.h"

class Soil : public Plot {
public:
    std::string symbol() override;
    void end_day() override {} // No Op
    void water() override {} // No Op
    ~Soil() override = default;
};