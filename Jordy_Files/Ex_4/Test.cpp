#include <iostream>
#include "Track.h"

int main() {
    // Create a regular track
    Track track(10.0, 20.0, 30.0, 50.0);
    std::cout << "=== Reconstructed Track ===" << std::endl;
    track.printInfo();

    // Create a simulated track with PDG ID 11 (electron) and parent ID 22 (photon)
    SimulatedTrack simTrack(10.0, 20.0, 30.0, 50.0, 11, 22);
    std::cout << "\n=== Simulated Track ===" << std::endl;
    simTrack.printInfo();

    return 0;
}
