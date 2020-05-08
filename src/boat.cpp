#include "boat.h"
#include <QString>
/**
 * default constructore
 * @brief Boat::Boat
 */
Boat::Boat()
{
    this->type = "";
    this->length = 0.0;
    this->electric = false;
    this->capacity = 0;
}

/**
 * non-default constructore, takes all arguamnets
 * @brief Boat::Boat
 * @param type
 * @param length
 * @param electric
 * @param capacity
 */
Boat::Boat(QString type, double length, QString electric, int capacity)
{
    this->type = type;
    this->length = length;
    this->electric = electric;
    this->capacity = capacity;
}

/**
 * returns a QString of boat info
 * @brief Boat::toString
 * @return
 */
QString Boat::toString(){
    return "Type: " + getType() + " | Length: " + QString::number(getLength()) + "ft | Electric: " + getElectric() + " | Capacity: " + QString::number(getCapacity());
}

/**
QString Boat::toString(){
    string s = "Type: " + getType().toStdString() + " | Length: ";
    s += to_string(getLength());
    s += " | Electric: ";
    s += getElectric().toStdString();
    s += " | Capacity: ";
    s += to_string(getCapacity());
    return QString::fromStdString(s);
}
**/
