#include "location.h"

/**
 * default constructore
 * @brief Location::Location
 */
Location::Location()
{
    this->bodyOfWater = "";
    this->gps = "N/A";
    this->address = "N/A";
}

/**
 * non-default constructore, takes all arguamnets
 * @brief Location::Location
 * @param bodyOfWater
 * @param gps
 * @param address
 */
Location::Location(QString bodyOfWater, QString gps, QString address)
{
    this->bodyOfWater = bodyOfWater;
    this->gps = gps;
    this->address = address;
}

/**
 * returns a QString of the location info
 * @brief Location::toString
 * @return
 */
QString Location::toString(){
    return "Body of water type: " + getBodyOfWater() + " | GPS address: " + getGps() + " | Address: " + getAddress();
}
