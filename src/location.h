#ifndef LOCATION_H
#define LOCATION_H

#include <QString>
using namespace std;

class Location
{
private:
    QString bodyOfWater;
    QString gps;
    QString address;
public:
    // constructors
    Location();
    Location(QString bodyOfWater, QString gps, QString address);

    // methods
    QString toString();

    // getters and setters
    QString getBodyOfWater() const {
        return bodyOfWater;
    };
    QString getGps() const {
        return gps;
    };
    QString getAddress() const {
        return address;
    };
    void setBodyOfWater(QString bodyOfWater) {
        this->bodyOfWater = bodyOfWater;
    };
    void setGps(QString gps) {
        this->gps = gps;
    };
    void setAddress(QString address) {
        this->address = address;
    };
};

#endif // LOCATION_H
