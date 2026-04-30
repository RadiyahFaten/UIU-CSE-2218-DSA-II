#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Train
{

    int arrival;
    int departure;
};

bool compareDepartureTime(Train a, Train b)
{
    return a.departure < b.departure;
}

int main()
{
    vector<Train> trains = {
        {8, 12},
        {6, 9},
        {11, 14},
        {2, 7},
        {1, 7},
        {12, 20},
        {7, 12},
        {13, 19}};

    sort(trains.begin(), trains.end(), compareDepartureTime);

    int countTrain = 0;
    int last_dep_time = INT_MIN;

    cout << "Trains selected: " << endl;

    for (Train train : trains)
    {
        if (train.arrival >= last_dep_time + 1)
        {
            cout << "[" << train.arrival << ", " << train.departure << ")" << endl;
            countTrain++;
            last_dep_time = train.departure;
        }
    }

    cout << "Maximum number of trains = " << countTrain << endl;
}