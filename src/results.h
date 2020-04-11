#ifndef RESULTS_H
#define RESULTS_H

#include <string>
using namespace std;

class Results
{
private:
    int numberOfFishWorthKeeping;
    bool success;
    bool myFault;
public:
    // constructors
    Results();
    Results(int numFish, bool success, bool fault);

    // getters and setters
    int getNumberOfFishWorthKeeping() const {
        return numberOfFishWorthKeeping;
    };
    bool getSuccess()const {
        return success;
    };
    bool getMyFault() const {
        return myFault;
    };
    void setNumberOfFishWorthKeeping(int numberOfFishWorthKeeping){
        this->numberOfFishWorthKeeping = numberOfFishWorthKeeping;
    };
    void setSuccess(bool success){
        this->success = success;
    };
    void setMyFault(bool myFault){
        this->myFault = myFault;
    };
};

#endif // RESULTS_H
