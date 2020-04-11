#ifndef FISH_H
#define FISH_H

#include <string>
using namespace std;

class Fish
{
private:
    int limitNumber;
    int minSizeRequirement;
    string species;
public:
    // constructors
    Fish();
    Fish(int limNum, int minSizeReq, string spec);

    //getters and setters
    int getLimitNumber() const {
        return limitNumber;
    };
    int getMinSizeRequirement() const {
        return minSizeRequirement;
    };
    string getSpecies() const {
        return species;
    };
    void setLimitNumber(int limitNumber) {
        this->limitNumber = limitNumber;
    };
    void setMinSizeRequirement(int minSizeRequirement) {
        this->minSizeRequirement = minSizeRequirement;
    };
    void setSpecies(string species) {
        this->species = species;
    };
};

#endif // FISH_H
