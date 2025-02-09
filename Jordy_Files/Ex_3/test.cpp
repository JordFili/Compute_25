#include <iostream>
#include "MissingET.h"

int main() {
    // Create a MET with some values
    MissingET met(30.0, 40.0);

    std::cout << "MET x: " << met.getMETx() << std::endl;
    std::cout << "MET y: " << met.getMETy() << std::endl;
    std::cout << "MET Magnitude: " << met.getMET() << std::endl;
    std::cout << "MET Phi: " << met.getPhi() << std::endl;

    return 0;
}
