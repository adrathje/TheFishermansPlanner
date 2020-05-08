#include "weather.h"

/**
 * default constructore
 * @brief Weather::Weather
 */
Weather::Weather(){}

/**
 * non-default constructore, takes all arguamnets
 * @brief Weather::Weather
 * @param temp
 * @param windSpd
 * @param windDir
 */
Weather::Weather(double temp, double windSpd, QString windDir)
{
    this->temperature = temp;
    this->windSpeed = windSpd;
    this->windDirection = windDir;
}

/**
 * returns a QString of the weather info
 * @brief Weather::toString
 * @return
 */
QString Weather::toString(){
    return "Temperature: " + QString::number(getTemperature()) + " degrees | Wind speed: " +
            QString::number(getWindSpeed()) + " mph | Wind Direction: " + getWindDirection();
}
