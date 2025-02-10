#ifndef TRACK_H
#define TRACK_H

#include <cmath>
#include <iostream>

class Track {
private:
    double px, py, pz, E;

public:
    Track(double px, double py, double pz, double E);

    double getPx() const;
    double getPy() const;
    double getPz() const;
    double getE() const;
