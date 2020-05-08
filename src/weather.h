#ifndef WEATHER_H
#define WEATHER_H

#include <QString>
using namespace std;

class Weather
{
private:
    double temperature;
    double windSpeed;
    QString windDirection = "No Wind";
public:
    // constructors
    Weather();
    Weather(double temp, double windSpd, QString windDir);

    // methods
    QString toString();

    //getters and setters
    double getTemperature() const {
        return temperature;
    };
    double getWindSpeed() const {
        return windSpeed;
    };
    QString getWindDirection() const {
        return windDirection;
    };
    void setTemperature(double temperature) {
        this->temperature = temperature;
    };
    void setWindSpeed(double windSpeed) {
        this->windSpeed = windSpeed;
    };
    void setSpecies(QString windDirection) {
        this->windDirection = windDirection;
    };
};

#endif // WEATHER_H
