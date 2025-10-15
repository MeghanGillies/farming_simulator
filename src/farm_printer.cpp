#include <string>
#include <sstream>

#include "farm.hpp"
#include "farm_printer.h"

FarmPrinter::FarmPrinter(Farm *f) : farm(f) {}

std::string FarmPrinter::pp()  {
    std::stringstream ss;

    for (int i = 0; i < farm->num_of_rows(); i++) {
        for (int j = 0; j < farm->num_of_columns(); j++) {
            ss << "\t" << farm->get_symbol(i,j);
        }
        ss << "\n";
    }

    return ss.str();
}