#ifndef WEATHER_H
#define WEATHER_H

#include <boat.h>
#include <fish.h>
#include <vector>
#include <string>
using namespace std;

class Weather
{
private:
    double temperature;
    double windSpeed;
    string windDirection = "No Wind";
public:
    // constructors
    Weather();
    Weather(double temp, double windSpd, string windDir);

    // methods
    string toString() {
        //return "Temperature: " << temperature << " Wind Speed: " << getWindSpeed() << " Wind Direction: " << getWindDirection();
        return to_string(getWindSpeed());
    };

    //getters and setters
    double getTemperature() const {
        return temperature;
    };
    double getWindSpeed() const {
        return windSpeed;
    };
    string getWindDirection() const {
        return windDirection;
    };
    void setTemperature(double temperature) {
        this->temperature = temperature;
    };
    void setWindSpeed(double windSpeed) {
        this->windSpeed = windSpeed;
    };
    void setSpecies(string windDirection) {
        this->windDirection = windDirection;
    };
};

#endif // WEATHER_H
