CXX = g++
CXXFLAGS = -Wall -std=c++17 -shared -fPIC

libmeasurement.so: measurement.h measurement.cpp
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    rm -f libmeasurement.so
