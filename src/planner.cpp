#include "planner.h"

/**
 * default constructore
 * @brief Planner::Planner
 */
Planner::Planner(){}

/**
 * non-default constructore
 * @brief Planner::Planner
 * @param name
 * @param fishingWeather
 * @param equipmentToBring
 */
Planner::Planner(string name, Weather fishingWeather, Equipment equipmentToBring){
    this->name = name;
    this->fishingWeather = fishingWeather;
    this->equipmentToBring = equipmentToBring;
}

/**
 * non-default constructore
 * @brief Planner::Planner
 * @param name
 * @param fishingWeather
 * @param equipmentToBring
 * @param boatBeingUsed
 */
Planner::Planner(string name, Weather fishingWeather, Equipment equipmentToBring, Boat boatBeingUsed){
    this->name = name;
    this->fishingWeather = fishingWeather;
    this->equipmentToBring = equipmentToBring;
    this->boatBeingUsed = boatBeingUsed;
}

