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
Weather::Weather(double temp, double windSpd, string windDir)
{
    this->temperature = temp;
    this->windSpeed = windSpd;
    this->windDirection = windDir;
}

