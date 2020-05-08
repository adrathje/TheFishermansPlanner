#include "plannercli.h"

//Austin Rathje

plannerCli::plannerCli(){
    start();
}

void plannerCli::start(){
    mainMenu();
}

void plannerCli::mainMenu(){
    // local variables
    QTextStream qtin(stdin);
    bool valid = false;
    int choice;

    cout << "\n ------------------------------------ " << endl;
    cout << "| Welcome to The Fisherman's Planner |" << endl;
    cout << " ------------------------------------ " << endl;
    while(!valid) {
        cout << "1. View planners and/or add results to an existing planner \n2. Add planner" << endl;
        cin >> choice;

        // check if input was a valid number
        if(!cin || (choice > 2 || choice < 1))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "That is not a valid option, please try again.\n" << endl;
        } else {
            if(choice == 1){
                // local variable
                int numOfPlanners = getCount();

                // check if there is any data to show
                if(numOfPlanners == 0){
                    cout << "There is currently no plans saved, try adding some and come back!" << endl;
                } else {
                    // pull all planners from the table and put them in a vectore
                    vector<Planner> allPlanners;
                    for(int i = 1; i <= numOfPlanners; i++){
                        allPlanners.push_back(getPlanner(i));
                    }

                    // display all planners
                    for(Planner p : allPlanners){
                        cout << p.toString().toStdString() << "\n";
                    }

                    // ask if user wants to add a result to an existing planner
                    cout << "Would you like to add results to an existing planner? (y/n) ";
                    if(askForYesOrNo()){
                        // create a new Planner object to be filled with user input
                        Planner temp = Planner();

                        // ask user for ID of the planner they want to update
                        long plannerToUpdate;
                        cout << "Which planner would you like to add results to? (use ID#) ";
                        plannerToUpdate = askForInteger();

                        // check if a planner with that ID exists
                        if(plannerToUpdate <= getCount() && plannerToUpdate > 0){
                            // pull up the planner data after finding it by plannerId
                            temp = getPlanner(plannerToUpdate);

                            // ask the user results questions
                            resultsQuestions(temp);
                            updateResults(temp);
                        } else {
                            cout << "\nNo planner with that ID was found...";
                        }
                    } else {
                        // ask if they want to exit program
                        cout << "Would you like to exit the program? (y/n) ";
                        if(askForYesOrNo()){
                            valid = true;
                            cout << "See you around!" << endl;
                        }
                    }
                }
            } else {
                // create a new Planner object to be filled with user input
                Planner newPlanner = Planner();

                // ask the user about basic planner questions
                plannerQuestions(newPlanner);

                // ask the user equipment questions
                equipmentQuestions(newPlanner);

                // ask the user fish questions
                fishQuestions(newPlanner);

                // ask the user location questions
                locationQuestions(newPlanner);

                // ask the user weather questions
                weatherQuestions(newPlanner);

                // save the new planner to the database
                newPlanner.setPlannerId(getCount() + 1);
                addPlanner(newPlanner);

                cout << "\nWould you like to go back to the main menu? (y/n) " << endl;
                if(!askForYesOrNo()){
                    valid = true;
                    cout << "See you around!" << endl;
                }
            }
        }
    }
}

/**
 * asks the user for input about the boat
 * @brief plannerCli::boatQuestions
 * @param planner
 */
void plannerCli::boatQuestions(Planner &planner){
    // local variables
    QString type;
    double length;
    bool electric;
    int capacity;
    QTextStream qtin(stdin);
    Boat newBoat = Boat();

    // getting input about the boat type
    cout << "\n---- Boat Questions ----" << endl;
    cout << "\nWhat type of boat will be used? ";
    type = qtin.readLine();
    newBoat.setType(type);

    // getting input about the boat's length
    cout << "What length is it? ";
    length = askForDouble();
    newBoat.setLength(length);

    // getting input about the boat moter
    cout << "Does the boat use an electric moter? (y/n) ";
    electric = askForYesOrNo();
    if(electric){
        newBoat.setElectric("Yes");
    } else {
        newBoat.setElectric("No");
    }

    // getting input about the boat capacity
    cout << "What is the boat's person capacity? ";
    capacity = askForInteger();
    newBoat.setCapacity(capacity);

    // update planner's boat info
    planner.setBoatBeingUsed(newBoat.toString());
    cout << "\nBoat informtion saved successfully..." << endl;
}

/**
 * asks the user for input about the equipment
 * @brief plannerCli::equipmentQuestions
 * @param planner
 */
void plannerCli::equipmentQuestions(Planner &planner){
    // local variables
    int lineWeight;
    QString lure;
    QString bait;
    QTextStream qtin(stdin);

    // getting input about line weight
    cout << "\n---- Equipment Questions ----" << endl;
    cout << "\nWhat line weight will be used? (pound test) ";
    lineWeight = askForInteger();

    // getting input about lures
    cout << "What lure(s) will be used? (separated by commas): ";
    lure = qtin.readLine();

    // getting input about bait
    cout << "What bait will be used, if any? ";
    bait = qtin.readLine();

    // create equipment object with user input
    Equipment equipment = Equipment(lineWeight, lure, bait);

    // update planner's equipment info
    planner.setEquipmentToBring(equipment.toString());
    cout << "\nEquipment informtion saved successfully..." << endl;
}

/**
 * asks the user for input about the fish
 * @brief plannerCli::fishQuestions
 * @param planner
 */
void plannerCli::fishQuestions(Planner &planner){
    // local variables
    int limitNumber;
    double minSizeRequirement;
    QString species;
    QTextStream qtin(stdin);

    // getting input about fish species
    cout << "\n---- Fish Questions ----" << endl;
    cout << "\nName of fish species? ";
    species = qtin.readLine();

    // getting input about fish limit number
    cout << "What is the limit number? ";
    limitNumber = askForInteger();

    // getting input about fish minimum size requirements
    cout << "What is the minimum size requirement in inches? ";
    minSizeRequirement = askForDouble();

    // create equipment object from user input
    Fish fish = Fish(limitNumber, minSizeRequirement, species);

    // update planner's fish info
    planner.setFish(fish.toString());
    cout << "\nFish informtion saved successfully..." << endl;
}

/**
 * asks the user for input about the location
 * @brief plannerCli::locationQuestions
 * @param planner
 */
void plannerCli::locationQuestions(Planner &planner){
    // local variables
    QString bodyOfWater;
    QString gps;
    QString address;
    QTextStream qtin(stdin);

    // getting input about the type of body of water
    cout << "\n---- Location Questions ----" << endl;
    cout << "\nType of body of water: ";
    bodyOfWater = qtin.readLine();

    // getting input about normal location address
    cout << "Location address: ";
    address = qtin.readLine();

    // getting input about GPS address
    // link to get GPS location https://www.gps-coordinates.net/
    cout << "GPS address, if not applicable type N/A (Example: 42.067626,-93.624523 in decimal degrees): ";
    gps = qtin.readLine();

    // create location object from user input
    Location location = Location(bodyOfWater, gps, address);

    // update planner's location info
    planner.setLocation(location.toString());
    cout << "\nLocation informtion saved successfully..." << endl;
}

/**
* ask the user for a planner name and boat details
* @brief plannerCli::plannerQuestions
* @param planner
*/
void plannerCli::plannerQuestions(Planner &planner){
    QTextStream qtin(stdin);
    QString plannerName;

    // ask the user for a planner name and save it
    cout << "What would you like to name your planner? ";
    plannerName = qtin.readLine();
    planner.setName(plannerName);
    cout << "Name saved successfully..." << endl;

    // ask the user if they want to add a boat
    cout << "\nWould you like to add a boat? (y/n) ";
    if(askForYesOrNo()){
        boatQuestions(planner);
    } else {
        cout << "\nWho needs a boat anyways, moving on!" << endl;
    }
}

/**
 * asks the user for input about the weather
 * @brief plannerCli::weatherQuestions
 * @param planner
 */
void plannerCli::weatherQuestions(Planner &planner){
    // local variables
    double temperature;
    double windSpeed;
    QString windDirection;
    QTextStream qtin(stdin);

    // getting input about the temperature
    cout << "\n---- Weather Questions ----" << endl;
    cout << "\nWhat will be the temperature? ";
    temperature = askForDouble();

    // getting input about the wind speed
    cout << "What will be the wind speed? ";
    windSpeed = askForDouble();

    // getting input about wind direction
    cout << "What will be the wind direction? ";
    windDirection = qtin.readLine();

    // create weather object from user input
    Weather weather = Weather(temperature, windSpeed, windDirection);

    // update planner's weather info
    planner.setFishingWeather(weather.toString());
    cout << "\nWeather informtion saved successfully..." << endl;
}

/**
 * asks the user for input about the results
 * @brief plannerCli::resultsQuestions
 * @param planner
 */
void plannerCli::resultsQuestions(Planner &planner){
    // local variables
    int numberOfFishWorthKeeping;
    bool success;

    // getting input about the number of fish worth keeping
    cout << "\n---- Results Questions ----" << endl;
    cout << "\nWhat was the number of fish worth keeping? ";
    numberOfFishWorthKeeping = askForInteger();

    // getting input about the success
    cout << "Would you call it a success? (y/n) ";
    success = askForYesOrNo();

    // create results object from user input
    Results results = Results(numberOfFishWorthKeeping, success, false);

    // update planner's results info
    planner.setResults(results.toString());
    cout << "Results saved to planner #" << planner.getPlannerId() << " successfully!" << endl;
}

/**
 * searches the database by plannerId and assigns the values to the desired planner
 * @brief plannerCli::getPlanner
 * @param plannerId
 * @param planner
 */
Planner plannerCli::getPlanner(long long plannerId){
    QSqlQuery query;
    Planner planner = Planner();
    query.prepare("SELECT PlannerId, Name, Fish, Locations, Weather, Equipment, Boats, Results FROM Planners WHERE PlannerId = ?");
    query.addBindValue(plannerId);

    if(!query.exec()){
        cout <<"Failed to get planner from database";
    }
    query.next();
    planner.setPlannerId(query.value(0).toLongLong());
    planner.setName(query.value(1).toString());
    planner.setFish(query.value(2).toString());
    planner.setLocation(query.value(3).toString());
    planner.setFishingWeather(query.value(4).toString());
    planner.setEquipmentToBring(query.value(5).toString());
    planner.setBoatBeingUsed(query.value(6).toString());
    planner.setResults(query.value(7).toString());

    return planner;
}

/**
 * returns the number of rows in the Planners table
 * @brief plannerCli::getCount
 * @return
 */
int plannerCli::getCount(){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Planners");
    query.exec();
    query.next();
    return query.value(0).toInt();
}

/**
 * updates the results field
 * @brief plannerCli::updateResults
 * @param planner
 */
void plannerCli::updateResults(Planner &planner) {
    QSqlQuery query;
    long long id = planner.getPlannerId();
    query.prepare("UPDATE Planners SET Results = :results WHERE PlannerId = :id");
    query.bindValue(":results", planner.getResults());
    query.bindValue(":id", id);
    query.exec();
}

/**
 * adds a new planner to the Planners table
 * @brief plannerCli::addPlanner
 * @param id
 * @param name
 * @param fish
 * @param location
 * @param weather
 * @param equipment
 * @param boat
 * @param result
 */
void plannerCli::addPlanner(Planner planner){
    QSqlQuery qry;
    int id = planner.getPlannerId();

    qry.prepare("INSERT INTO Planners ("
                "PlannerId,"
                "Name,"
                "Fish,"
                "Locations,"
                "Weather,"
                "Equipment,"
                "Boats,"
                "Results)"
                "VALUES (?,?,?,?,?,?,?,?)");

    qry.addBindValue(id);
    qry.addBindValue(planner.getName());
    qry.addBindValue(planner.getFish());
    qry.addBindValue(planner.getLocation());
    qry.addBindValue(planner.getFishingWeather());
    qry.addBindValue(planner.getEquipmentToBring());
    qry.addBindValue(planner.getBoatBeingUsed());
    qry.addBindValue(planner.getResults());

    if(!qry.exec()){
        qDebug()<<"Failed to add planner to database";
    }
}

/**
 * prompt user for yes or no input, if valid return it
 * @brief plannerCli::askForYesOrNo
 * @return
 */
bool plannerCli::askForYesOrNo() {
    // local variables
    QTextStream qtin(stdin);
    QString input;

    while(true){
        cout << "Enter answer now: ";
        qtin >> input;

        // check if the input is valid
        if(input == "y" || input == "Y"){
            return true;
        } else if(input == "n" || input == "N"){
            return false;
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input format, must be (y/n). Please try again." << endl;
        }
    }
}

/**
 * asks for user input and validates that it is a double and within range then returns it
 * @brief askForDouble
 * @return
 */
double plannerCli::askForDouble() {
    // local variables
    QTextStream qtin(stdin);
    QString input;
    bool exit = false;

    while(!exit){
        // prompt user for a number and save input
        cout << "Enter number now: ";
        qtin >> input;

        // check if the input is a double
        if(input.toDouble() && input.toDouble() > 0){
            exit = true;
        } else {
            cout << "\nInput must be a number and greater than zero. Please try again." << endl;
        }
    }
    return input.toDouble();
}

/**
 * asks for user input and validates that it is an integer and within range then returns it
 * @brief askForInteger
 * @return
 */
int plannerCli::askForInteger() {
    // local variables
    QTextStream qtin(stdin);
    QString input;
    bool exit = false;

    while(!exit){
        // prompt user for a number and save input
        cout << "Enter number now: ";
        qtin >> input;

        // check if the input is a double
        if(input.toInt() && input.toInt() > 0){
            exit = true;
        } else {
            cout << "\nInput must be a number and greater than one. Please try again." << endl;
        }
    }
    return input.toInt();
}
