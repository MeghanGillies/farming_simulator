#include <string>

#include "carrot.h"

Carrot::Carrot() {
    current_symbol = baby;
}

std::string Carrot::symbol() {
    return current_symbol;
}