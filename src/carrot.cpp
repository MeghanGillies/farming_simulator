#include <string>

#include "carrot.h"

std::string Carrot::symbol() {
    if (age < age_to_sprout) {
        return tilled_soil;
    } else if (age < age_to_grow) {
        return baby;
    } else {
        return grown;
    }
}

void Carrot::water() {
    is_watered = true;
}

void Carrot::end_day() {
    if (is_watered) {
        age += 2;
        is_watered = false;
    } else {
        age += 1;
    }
}

bool Carrot::is_grown() {
    if ( symbol() == grown ) {
        return true;
    } else {
        return false;
    }
}