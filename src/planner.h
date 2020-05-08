#ifndef PLANNER_H
#define PLANNER_H

#include "fish.h"
#include "location.h"
#include "weather.h"
#include "equipment.h"
#include "boat.h"
#include "results.h"
#include <iostream>
#include <vector>
#include <QString>

using namespace std;

class Planner
{
private:
    long plannerId = 0;
    QString name = "";
    QString fish = "";
    QString location = "";
    QString fishingWeather;
    QString equipmentToBring;
    QString boatBeingUsed = "No boat was used.";
    QString results = "None have been submitted yet.";
public:
    // constructors
    Planner();
    Planner(QString name, QString fishingWeather, QString equipmentToBring);
    Planner(QString name, QString fishingWeather, QString equipmentToBring, QString boatBeingUsed);

    // methods
    QString toString();

    // getters
    long getPlannerId() const {
        return plannerId;
    }
    QString getName() const{
        return name;
    };
    QString getFish() const{
        return fish;
    };
    QString getLocation() const {
        return location;
    };
    QString getFishingWeather() const {
        return fishingWeather;
    };
    QString getEquipmentToBring() const {
        return equipmentToBring;
    };
    QString getBoatBeingUsed() const {
        return boatBeingUsed;
    };
    QString getResults() const {
        return results;
    };

    // setters
    void setPlannerId(long id) {
        this->plannerId = id;
    }
    void setName(QString name) {
        this->name = name;
    };
    void setFish(QString fish) {
        this->fish = fish;
    };
    void setLocation(QString location) {
        this->location = location;
    };
    void setFishingWeather(QString fishingWeather) {
        this->fishingWeather = fishingWeather;
    };
    void setEquipmentToBring(QString equipmentToBring) {
        this->equipmentToBring = equipmentToBring;
    };
    void setBoatBeingUsed(QString boatBeingUsed) {
        this->boatBeingUsed = boatBeingUsed;
    };
    void setResults(QString results) {
        this->results = results;
    };
};

#endif // PLANNER_H
