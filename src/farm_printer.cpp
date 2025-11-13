#include <string>
#include <sstream>

#include "farm_printer.h"
#include "farm.hpp"
#include "player.h"

FarmPrinter::FarmPrinter(Farm *f, Player *p) : farm(f), player(p) {}

std::string FarmPrinter::pp()  {
    std::stringstream ss;
    ss << "\n";

    for (int i = 0; i < farm->num_of_rows(); i++) {
        for (int j = 0; j < farm->num_of_columns(); j++) {
            ss << "  ";

            if ( player->position() == (Coordinate(i, j)) ) {
                ss << player->symbol();
            } else {
                ss << farm->get_symbol(Coordinate(i,j));
            }

            ss << "\t";
        }
        ss << "\n\n";
    }

    return ss.str();
}