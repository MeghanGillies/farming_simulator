#include <string>

#include "carrot.h"

std::string Carrot::symbol() {
    if (age == 0) {
        return baby;
    } else {
        return grown;
    }
}

void Carrot::end_day() {
    age += 1;
}