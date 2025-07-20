#include "TrainSystem.h"
#include <iostream>
using namespace std;

void TrainSystem::addTrain(const Train& train) {
    trains.push_back(train);
}

void TrainSystem::printAllTrains() const {
    if (trains.empty()) {
        cout << "Train list is empty" << endl;
        return;
    }
    cout << "List of all trains:" << endl;
    for (const auto& t : trains) {
        cout << "Number: " << t.getNumber()
            << ", Departure time: " << t.getDepartureTime()
            << ", Destination station: " << t.getDestinationStation() << endl;
    }
}

bool TrainSystem::printTrainByNumber(int number) const {
    for (const auto& t : trains) {
        if (t.getNumber() == number) {
            cout << "Information for train #" << number << ":\n";
            cout << "Departure time: " << t.getDepartureTime() << "\n";
            cout << "Destination station: " << t.getDestinationStation() << "\n";
            return true;
        }
    }
    cout << "Train with number " << number << " not found\n";
    return false;
}