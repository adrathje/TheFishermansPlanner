#ifndef FISH_H
#define FISH_H

#include <QString>
using namespace std;

class Fish
{
private:
    int limitNumber;
    double minSizeRequirement;
    QString species;
public:
    // constructors
    Fish();
    Fish(int limNum, double minSizeReq, QString spec);

    // methods
    QString toString();

    //getters and setters
    int getLimitNumber() const {
        return limitNumber;
    };
    double getMinSizeRequirement() const {
        return minSizeRequirement;
    };
    QString getSpecies() const {
        return species;
    };
    void setLimitNumber(int limitNumber) {
        this->limitNumber = limitNumber;
    };
    void setMinSizeRequirement(double minSizeRequirement) {
        this->minSizeRequirement = minSizeRequirement;
    };
    void setSpecies(QString species) {
        this->species = species;
    };
};

#endif // FISH_H
