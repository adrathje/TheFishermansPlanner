#include "equipment.h"

/**
 * default constructore
 * @brief Equipment::Equipment
 */
Equipment::Equipment()
{
    this->lineWeight = 0.0;
    this->lure = "";
    this->bait = "";
}

/**
 * non-default constructore, takes all arguamnets
 * @brief Equipment::Equipment
 * @param lineWt
 * @param l
 * @param b
 */
Equipment::Equipment(int lineWt, string l, string b)
{
    this->lineWeight = lineWt;
    this->lure = l;
    this->bait = b;
}
