#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <QString>
using namespace std;

class Equipment
{
private:
    int lineWeight;
    QString lure;
    QString bait;
public:
    // constructors
    Equipment();
    Equipment(int lineWt, QString l, QString b);

    // methods
    QString toString();

    //getters and setters
    int getLineWeight() const {
        return lineWeight;
    };
    QString getLure() const {
        return lure;
    };
    QString getBait() const {
        return bait;
    };
    void setLineWeight(int lineWeight) {
        this->lineWeight = lineWeight;
    };
    void setLure(QString lure) {
      this->lure = lure;
    };
    void setBait(QString bait) {
      this->bait = bait;
    };
};

#endif // EQUIPMENT_H
