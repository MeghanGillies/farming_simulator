#include <string>
#include "spinach.h"

std::string Spinach::symbol() {
    if (age < age_to_sprout) {
        return tilled_soil;
    } else if (age < age_to_grow) {
        return baby;
    } else {
        return grown;
    }
}

void Spinach::water() {
    is_watered = true;
}

void Spinach::end_day() {
    if (is_watered) {
        age += 2;
        is_watered = false;
    } else {
        age += 1;
    }
}

bool Spinach::is_grown() {
    if ( symbol() == grown ) {
        return true;
    } else {
        return false;
    }
}