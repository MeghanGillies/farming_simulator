#include <iostream>

#include "src/farm.hpp"
#include "src/farm_printer.h"
#include "src/carrot.h"

int main() {
    Farm farm(5,8);
    FarmPrinter printer(&farm);
    std::cout << printer.pp() << std::endl;

    Carrot *carrot = new Carrot();
    farm.plant(1, 2, carrot);
    farm.plant(2, 5, carrot);
    farm.plant(0, 3, carrot);

    std::cout << printer.pp() << std::endl;

    farm.harvest(1, 2);

    std::cout << printer.pp() << std::endl;

    return 0;
}
