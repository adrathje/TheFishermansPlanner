#include <QtSql>
#include <plannercli.h>

/***************************************************************************
* Program Name  : TheFishermansPlanner
* Author        : Austin Rathje
* Created       : 5/7/2020
* Version       : 1.0
* OS            : Windows 10
* Framework     : Qt
* Description   : This program helps fishermen keep track of future and past
*                 fishing plans. Each fishing plan has a results section that
*                 can be added after the trip takes place. The program utilizes
*                 SQLite to store and use the planners.
***************************************************************************/

using namespace std;

int main()
{
    QSqlDatabase plannerdb;
    plannerdb = QSqlDatabase::addDatabase("QSQLITE");
    plannerdb.setDatabaseName("C:planner.sqlite");

    // try opening the database
    try {
        plannerdb.open();
    } catch (const char* exStr) {
        cout << "Had an issue trying to open the database. Error: " << exStr << endl;
    }

    // create Planners table
    QString createTableQuery =("CREATE TABLE Planners ("
                               "PlannerId INTEGER,"
                               "Name TEXT, "
                               "Fish TEXT, "
                               "Locations TEXT, "
                               "Weather TEXT, "
                               "Equipment TEXT, "
                               "Boats TEXT, "
                               "Results TEXT);");

    // try to create the database
    QSqlQuery qry;
    try {
        qry.exec(createTableQuery);
    } catch (const char* exStr) {
        cout << "Had an issue creating the database. Error: " << exStr << endl;
    }

    // start the CLI
    plannerCli p = plannerCli();

    // close the database
    plannerdb.close();

    return 0;
}
