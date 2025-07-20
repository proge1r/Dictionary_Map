#include "Train.h"

using namespace std;

Train::Train(int number, const string& departure_time, const string& destination_station)
    : number(number), departure_time(departure_time), destination_station(destination_station) {
}

int Train::getNumber() const {
    return number;
}

string Train::getDepartureTime() const {
    return departure_time;
}

string Train::getDestinationStation() const {
    return destination_station;
}