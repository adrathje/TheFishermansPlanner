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
Fish::Fish(int limNum, int minSizeReq, string spec)
{
    this->limitNumber = limNum;
    this->minSizeRequirement = minSizeReq;
    this->species = spec;
}
