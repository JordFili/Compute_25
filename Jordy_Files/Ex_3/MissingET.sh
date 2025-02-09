#ifndef MISSING_ET_H
#define MISSING_ET_H

class MissingET {
private:
    double met_x; // x-component of MET
    double met_y; // y-component of MET

public:
    MissingET(double x, double y);

    double getMET() const;
    double getMETx() const;
    double getMETy() const;
    double getPhi() const;
};

#endif // MISSING_ET_H
