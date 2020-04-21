#include "weather.h"
#include "planner.h"
#include <QDebug>
#include <QtSql>
#include <iostream>

//Austin Rathje

using namespace std;

int main()
{
    cout << "start" << endl;
    QSqlDatabase plannerdb;
    plannerdb = QSqlDatabase::addDatabase("QSQLITE");
    plannerdb.setDatabaseName("C:/sqlite/db.sqlite");

    // try opening the database
    try {
        plannerdb.open();
    } catch (const char* exStr) {
        cout << "Had an issue trying to open the database. Error: " << exStr << endl;
    }

    // create weather table
    QString query = "CREATE TABLE weather ("
                    "Temperature double,"
                    "WindSpeed double,"
                    "WindDirection VARCHAR(20));";

    // create query
    QSqlQuery qry;

    // try to create the database
    try {
        qry.exec(query);
    } catch (const char* exStr) {
        cout << "Had an issue creating the database. Error: " << exStr << endl;
    }

    // close the database
    plannerdb.close();
cout << "end" << endl;
    Weather w = Weather(78, 12.5, "NW");
    Equipment e = Equipment(7, "none", "worm");
    Boat b = Boat("paddle boat", 9, false, 2);

    // create a vector along with some locations to put in it
    Location location1 = Location("lake", "42.071609178828034,-93.62508472420431", "Ada Hayden Lake, Waterbury Circle, Ames, IA 50010");
    Location location2 = Location();
    vector<Location> locations {location1, location2};

    // create a vector along with some fish to put in it
    Fish fish1 = Fish(4, 13, "Bass");
    Fish fish2 = Fish(10, 3, "Sunny");
    Fish fish3 = Fish(0, 984, "Blue whale");
    vector<Fish> fish {fish1, fish2, fish3};

    Planner newPlanner = Planner("Test Planner", w, e, b);
    newPlanner.setFishList(fish);
    newPlanner.setLocationList(locations);

    cout << "~~~~~~ Planner Name: " << newPlanner.getName() << " ~~~~~~" << endl << endl;
    cout << "***** Fish List *****" << endl;
    cout << "(" << newPlanner.getFishListSize() << " different types of fish)" << endl;
    for(Fish f : newPlanner.getFishList()){
        cout << "Spcies: " << f.getSpecies();
        cout << " | Limit number: " << f.getLimitNumber();
        cout << " | Minimum size requirment: " << f.getMinSizeRequirement() << endl;
    }
    cout << "\n***** Location List *****" << endl;
    cout << "(" << newPlanner.getLocationListSize() << " different locations)" << endl;
    for(Location l : newPlanner.getLocationList()){
        cout << "Body of water: " << l.getBodyOfWater();
        cout << " | GPS: " << l.getGps();
        cout << " | Address: " << l.getAddress() << endl;
    }
    cout << "\n***** Weather ***** " << endl;
    cout << "Temperature: " << newPlanner.getFishingWeather().getTemperature() << " degress" << endl;
    cout << "Wind speed: " << newPlanner.getFishingWeather().getWindSpeed() << " mph" << endl;
    cout << "Wind direction: " << newPlanner.getFishingWeather().getWindDirection() << endl;

    cout << "\n***** Equipment To Bring *****" << endl;
    cout << "Line weight: " << newPlanner.getEquipmentToBring().getLineWeight() << " (pounds)" << endl;
    cout << "Lure: " << newPlanner.getEquipmentToBring().getLure() << endl;
    cout << "Bait: " << newPlanner.getEquipmentToBring().getBait() << endl;

    cout << "\n***** Boat Info *****" << endl;
    cout << "Type: " << newPlanner.getBoatBeingUsed().getType() << endl;
    cout << "Length: " << newPlanner.getBoatBeingUsed().getType() << endl;
    cout << "Is electric: " << newPlanner.getBoatBeingUsed().getElectric() << endl;
    cout << "Capacity: " << newPlanner.getBoatBeingUsed().getCapacity() << endl;

    cout << "\n***** Results *****" << endl;



    return 0;
}
