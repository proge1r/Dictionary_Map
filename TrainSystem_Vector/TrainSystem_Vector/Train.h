#ifndef TRAIN_H
#define TRAIN_H
#include <string>
using namespace std;

class Train {
private:
    int number;
    string departure_time;
    string destination_station;
public:
    Train(int number, const string& departure_time, const string& destination_station);

    int getNumber() const;
    string getDepartureTime() const;
    string getDestinationStation() const;
};

#endif