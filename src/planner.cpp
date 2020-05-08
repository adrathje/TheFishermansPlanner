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
Planner::Planner(QString name, QString fishingWeather, QString equipmentToBring){
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
Planner::Planner(QString name, QString fishingWeather, QString equipmentToBring, QString boatBeingUsed){
    this->name = name;
    this->fishingWeather = fishingWeather;
    this->equipmentToBring = equipmentToBring;
    this->boatBeingUsed = boatBeingUsed;
}

/**
 * returns a QString of the planner info
 * @brief Planner::toString
 * @return
 */
QString Planner::toString(){
    return "----------------------------------------------------------------------------------\n                   Name: " +
            getName() + " | ID Number: " + QString::number(getPlannerId()) +
            "\n----------------------------------------------------------------------------------\n\nFISH INFO - " + getFish() +
            "\n\nLOCATION INFO - " + getLocation() + "\n\nWEATHER INFO - " + getFishingWeather() + "\n\nEQUIPMENT INFO - " +
            getEquipmentToBring() + "\n\nBOAT INFO - " + getBoatBeingUsed() + "\n\nRESULTS INFO - " + getResults() + "\n\n";
}

