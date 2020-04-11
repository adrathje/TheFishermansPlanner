#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location
{
private:
    string bodyOfWater;
    string gps;
    string address;
public:
    // constructors
    Location();
    Location(string bodyOfWater, string gps, string address);

    // getters and setters
    string getBodyOfWater() const {
        return bodyOfWater;
    };
    string getGps() const {
        return gps;
    };
    string getAddress() const {
        return address;
    };
    void setBodyOfWater(string bodyOfWater) {
        this->bodyOfWater = bodyOfWater;
    };
    void setGps(string gps) {
        this->gps = gps;
    };
    void setAddress(string address) {
        this->address = address;
    };
};

#endif // LOCATION_H
