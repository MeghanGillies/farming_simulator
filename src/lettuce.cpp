#include <string>
#include "lettuce.h"

std::string Lettuce::symbol() {
    if (age < age_to_sprout) {
        return tilled_soil;
    } else if (age < age_to_grow) {
        return baby;
    } else {
        return grown;
    }
}

void Lettuce::water() {
    is_watered = true;
}

void Lettuce::end_day() {
    if (is_watered) {
        age += 2;
        is_watered = false;
    } else {
        age += 1;
    }
}

bool Lettuce::is_grown() {
    if ( symbol() == grown ) {
        return true;
    } else {
        return false;
    }
}