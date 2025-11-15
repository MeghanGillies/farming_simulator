#include <string>
#include "brussel_sprouts.h"

std::string Brussel_Sprouts::symbol() {
    if (age < age_to_sprout) {
        return tilled_soil;
    } else if (age < age_to_grow) {
        return baby;
    } else {
        return grown;
    }
}

void Brussel_Sprouts::water() {
    is_watered = true;
}

void Brussel_Sprouts::end_day() {
    if (is_watered) {
        age += 2;
        is_watered = false;
    } else {
        age += 1;
    }
}

bool Brussel_Sprouts::is_grown() {
    if ( symbol() == grown ) {
        return true;
    } else {
        return false;
    }
}