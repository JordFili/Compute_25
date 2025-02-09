#include "MissingET.h"
#include <cmath>

MissingET::MissingET(double x, double y) : met_x(x), met_y(y) {}

double MissingET::getMET() const {
    return std::sqrt(met_x * met_x + met_y * met_y);
}

double MissingET::getMETx() const {
    return met_x;
}

double MissingET::getMETy() const {
    return met_y;
}

double MissingET::getPhi() const {
    return std::atan2(met_y, met_x);
}
