#include "results.h"

/**
 * default constructore
 * @brief Results::Results
 */
Results::Results()
{
    this->numberOfFishWorthKeeping = 0;
    this->success = false;
    this->myFault = false;
}

/**
 * non-default constructore, takes all arguamnets
 * @brief Results::Results
 * @param numFish
 * @param success
 * @param fault
 */
Results::Results(int numFish, bool success, bool fault)
{
    this->numberOfFishWorthKeeping = numFish;
    this->success = success;
    this->myFault = fault;
}

/**
 * returns a QString of the results info
 * @brief Results::toString
 * @return
 */
QString Results::toString(){
    return "Number of fish worth keeping: " + QString::number(getNumberOfFishWorthKeeping()) +
            " | Success: " + QVariant(getSuccess()).toString() + " | My fault: " + QVariant(getMyFault()).toString();
}

