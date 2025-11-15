#include <string>
#include "beet.h"

std::string Beet::symbol() {
    if (age < age_to_sprout) {
        return tilled_soil;
    } else if (age < age_to_grow) {
        return baby;
    } else {
        return grown;
    }
}

void Beet::water() {
    is_watered = true;
}

void Beet::end_day() {
    if (is_watered) {
        age += 2;
        is_watered = false;
    } else {
        age += 1;
    }
}

bool Beet::is_grown() {
    if ( symbol() == grown ) {
        return true;
    } else {
        return false;
    }
}