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

using namespace std;

class Planner
{
private:
    string name = "";
    vector<Fish> fishList;
    vector<Location> locationList;
    Weather fishingWeather;
    Equipment equipmentToBring;
    Boat boatBeingUsed;
    Results results;
public:
    // constructors
    Planner();
    Planner(string name, Weather fishingWeather, Equipment equipmentToBring);
    Planner(string name, Weather fishingWeather, Equipment equipmentToBring, Boat boatBeingUsed);

    // methods
    int getFishListSize(){
        return fishList.size();
    };
    int getLocationListSize(){
        return locationList.size();
    };

    // getters
    string getName() const{
        return name;
    };
    vector<Fish> getFishList() const{
        return fishList;
    };
    vector<Location> getLocationList() const {
        return locationList;
    };
    Weather getFishingWeather() const {
        return fishingWeather;
    };
    Equipment getEquipmentToBring() const {
        return equipmentToBring;
    };
    Boat getBoatBeingUsed() const {
        return boatBeingUsed;
    };
    Results getResults() const {
        return results;
    };

    // setters
    void setName(string name) {
        this->name = name;
    };
    void setFishList(vector<Fish> fishList) {
        this->fishList = fishList;
    };
    void setLocationList(vector<Location> locationList) {
        this->locationList = locationList;
    };
    void setFishingWeather(Weather fishingWeather) {
        this->fishingWeather = fishingWeather;
    };
    void setEquipmentToBring(Equipment equipmentToBring) {
        this->equipmentToBring = equipmentToBring;
    };
    void setBoatBeingUsed(Boat boatBeingUsed) {
        this->boatBeingUsed = boatBeingUsed;
    };
    void setResults(Results results) {
        this->results = results;
    };



};

#endif // PLANNER_H
