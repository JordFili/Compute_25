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
    public:
    Track(double px, double py, double pz, double E);

    double getPx() const;
    double getPy() const;
    double getPz() const;
    double getE() const;
    double getPT() const;
    double getEta() const;
    void printInfo() const;
};

class SimulatedTrack : public Track {
private:
    int particleID;
    int parentParticleID;

public:
    SimulatedTrack(double px, double py, double pz, double E, int pid, int parentID);

    int getParticleID() const;
    int getParentParticleID() const;
    void printInfo() const;
};

#endif