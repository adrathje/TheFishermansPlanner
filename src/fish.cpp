#include "fish.h"

/**
 * default constructore
 * @brief Fish::Fish
 */
Fish::Fish()
{
    this->limitNumber = 0;
    this->minSizeRequirement = 0;
    this->species = "";
}

/**
 * non-default constructore, takes all arguamnets
 * @brief Fish::Fish
 * @param limNum
 * @param minSizeReq
 * @param spec
 */
Fish::Fish(int limNum, double minSizeReq, QString spec)
{
    this->limitNumber = limNum;
    this->minSizeRequirement = minSizeReq;
    this->species = spec;
}

/**
 * returns a QString of the fish info
 * @brief Fish::toString
 * @return
 */
QString Fish::toString(){
    return "Fish limit number: " + QString::number(getLimitNumber()) + " | Minimum length requirement: " + QString::number(getMinSizeRequirement()) + " inches | Species: " + getSpecies();
}
