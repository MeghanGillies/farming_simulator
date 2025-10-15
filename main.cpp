#include <iostream>

#include "src/farm.hpp"
#include "src/farm_printer.h"
#include "src/carrot.h"

int main() {
    Farm farm(3,8);
    FarmPrinter printer(&farm);
    std::cout << printer.pp();

    Carrot *carrot = new Carrot();
    farm.plant(1, 2, carrot);

    std::cout << printer.pp();

    return 0;
}
