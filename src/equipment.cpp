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
Equipment::Equipment(int lineWt, QString l, QString b)
{
    this->lineWeight = lineWt;
    this->lure = l;
    this->bait = b;
}

/**
 * returns a QString of the equipment info
 * @brief Equipment::toString
 * @return
 */
QString Equipment::toString(){
    return "Line Weight: " + QString::number(getLineWeight()) + " | Lure(s): " + getLure() + " | Bait: " + getBait();
}
