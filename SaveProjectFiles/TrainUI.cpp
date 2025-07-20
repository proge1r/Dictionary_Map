#include "TrainUI.h"
#include <iostream>
#include <string>

using namespace std;

void inputTrains(TrainSystem& system) {
    int n;
    cout << "Enter the number of trains to add: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        int number;
        string departure_time;
        string destination_station;

        cout << "Train #" << (i + 1) << ":\n";
        cout << "Train number: ";
        cin >> number;
        cin.ignore();

        cout << "Departure time (xx:yy): ";
        getline(cin, departure_time);

        cout << "Destination station: ";
        getline(cin, destination_station);

        Train train(number, departure_time, destination_station);
        system.addTrain(train);
    }
}

void searchTrainLoop(const TrainSystem& system) {
    int search_number;
    bool found = false;

    while (!found) {
        cout << "\nEnter the train number to search for: ";
        cin >> search_number;

        found = system.printTrainByNumber(search_number);

        if (!found) {
            cout << "Please try again.\n";
        }
    }
}
