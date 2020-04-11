#ifndef BOAT_H
#define BOAT_H

#include <string>
using namespace std;

class Boat
{
private:
    string type;
    double length;
    bool electric;
    int capacity;
public:
    // constructores
    Boat();
    Boat(string type, double length, bool electric, int capacity);

    // getters and setters
    string getType() const {
        return type;
    };
    double getLength() const{
        return length;
    };
    bool getElectric(){
        return electric;
    };
    int getCapacity(){
        return capacity;
    };
    void setType(string type){
        this->type = type;
    };
    void setLength(double length){
        this->length = length;
    };
    void setElectric(bool electric){
        this->electric = electric;
    };
    void setCapacity(int capacity){
        this->capacity = capacity;
    };

};

#endif // BOAT_H
