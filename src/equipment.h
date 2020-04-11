#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
using namespace std;

class Equipment
{
private:
    int lineWeight;
    string lure;
    string bait;
public:
    // constructors
    Equipment();
    Equipment(int lineWt, string l, string b);

    // methods


    //getters and setters
    int getLineWeight() const {
        return lineWeight;
    };
    string getLure() const {
        return lure;
    };
    string getBait() const {
        return bait;
    };
    void setLineWeight(int lineWeight) {
        this->lineWeight = lineWeight;
    };
    void setLure(string lure) {
      this->lure = lure;
    };
    void setBait(string bait) {
      this->bait = bait;
    };
};

#endif // EQUIPMENT_H
