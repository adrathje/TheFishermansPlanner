#include "boat.h"

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
Boat::Boat(string type, double length, bool electric, int capacity)
{
    this->type = type;
    this->length = length;
    this->electric = electric;
    this->capacity = capacity;
}
