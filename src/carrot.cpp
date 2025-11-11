#include <string>

#include "carrot.h"

std::string Carrot::symbol() {
    if (age == 0) {
        return baby;
    } else {
        return grown;
    }
}

int Carrot::get_age() const { return age; }

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