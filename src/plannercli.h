#ifndef PLANNERCLI_H
#define PLANNERCLI_H
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QSqlDatabase>
#include <planner.h>
#include <QtSql>
#include <vector>

using namespace std;

class plannerCli
{
private:
    void mainMenu();
    void boatQuestions(Planner &planner);
    void equipmentQuestions(Planner &planner);
    void fishQuestions(Planner &planner);
    void locationQuestions(Planner &planner);
    void plannerQuestions(Planner &planner);
    void weatherQuestions(Planner &planner);
    void resultsQuestions(Planner &planner);
    void addPlanner(Planner planner);
    Planner getPlanner(long long plannerId);
    void updateResults(Planner &planner);
    int getCount();
    double askForDouble();
    int askForInteger();
    bool askForYesOrNo();
public:
    plannerCli();
    void start();
};

#endif // PLANNERCLI_H
