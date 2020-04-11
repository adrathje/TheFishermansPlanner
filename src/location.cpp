#include "location.h"

/**
 * default constructore
 * @brief Location::Location
 */
Location::Location()
{
    this->bodyOfWater = "";
    this->gps = "";
    this->address = "N/A";
}

/**
 * non-default constructore, takes all arguamnets
 * @brief Location::Location
 * @param bodyOfWater
 * @param gps
 * @param address
 */
Location::Location(string bodyOfWater, string gps, string address)
{
    this->bodyOfWater = bodyOfWater;
    this->gps = gps;
    this->address = address;
}
