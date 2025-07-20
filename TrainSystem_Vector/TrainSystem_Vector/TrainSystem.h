#ifndef TRAINSYSTEM_H
#define TRAINSYSTEM_H
#include <vector>
#include "Train.h"
using namespace std;

class TrainSystem {
public:
    void addTrain(const Train& train);
    void printAllTrains() const;
    bool printTrainByNumber(int number) const;

private:
    vector<Train> trains;
};

#endif