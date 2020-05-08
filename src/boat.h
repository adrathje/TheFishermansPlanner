#ifndef BOAT_H
#define BOAT_H

#include <QString>
using namespace std;

class Boat
{
private:
    QString type;
    double length;
    QString electric;
    int capacity;
public:
    // constructores
    Boat();
    Boat(QString type, double length, QString electric, int capacity);

    // methods
    QString toString();

    // getters and setters
    QString getType() const {
        return type;
    };
    double getLength() const{
        return length;
    };
    QString getElectric(){
        return electric;
    };
    int getCapacity(){
        return capacity;
    };
    void setType(QString type){
        this->type = type;
    };
    void setLength(double length){
        this->length = length;
    };
    void setElectric(QString electric){
        this->electric = electric;
    };
    void setCapacity(int capacity){
        this->capacity = capacity;
    };

};

#endif // BOAT_H
