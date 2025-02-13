#include "Track.h"

Track::Track(double px, double py, double pz, double E) : px(px), py(py), pz(pz), E(E) {}

double Track::getPx() const { return px; }
double Track::getPy() const { return py; }
double Track::getPz() const { return pz; }
double Track::getE() const { return E; }

double Track::getPT() const {
    return std::sqrt(px * px + py * py);
}

double Track::getEta() const {
    double p = std::sqrt(px * px + py * py + pz * pz);
    double theta = std::atan2(getPT(), pz);
    return -std::log(std::tan(theta / 2.0));
}

void Track::printInfo() const {
    std::cout << "Track Info: " << std::endl;
    std::cout << "  px: " << px << ", py: " << py << ", pz: " << pz << ", E: " << E << std::endl;
    std::cout << "  pT: " << getPT() << ", eta: " << getEta() << std::endl;
}

SimulatedTrack::SimulatedTrack(double px, double py, double pz, double E, int pid, int parentID)
    : Track(px, py, pz, E), particleID(pid), parentParticleID(parentID) {}

int SimulatedTrack::getParticleID() const { return particleID; }
int SimulatedTrack::getParentParticleID() const { return parentParticleID; }

void SimulatedTrack::printInfo() const {
    Track::printInfo();
    std::cout << "  Particle ID: " << particleID << ", Parent Particle ID: " << parentParticleID << std::endl;
}
