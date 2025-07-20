#include "TrainUI.h"
using namespace std;

int main() {
    TrainSystem system;

    inputTrains(system);
    system.printAllTrains();
    searchTrainLoop(system);

    return 0;
}
