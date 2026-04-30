#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Activity
{
    string name;
    int start_time;
    int finish_time;
};

// for sorting by finish time
bool compareFinishTime(Activity firstAct, Activity lastAct)
{
    return firstAct.finish_time < lastAct.finish_time;
}

int main()
{
    vector<int> startTimes = {3, 0, 5, 8, 5, 1};
    vector<int> finishTimes = {4, 6, 7, 9, 9, 2};

    // 2D Array to set all the activities
    vector<Activity> activities;

    for (int i = 0; i < startTimes.size(); i++)
    {
        // to store each activity
        Activity activity;

        activity.name = "A" + to_string(i);
        activity.start_time = startTimes[i];
        activity.finish_time = finishTimes[i];

        // push each activity in the list of activities, one by one
        activities.push_back(activity);
    }

    // sort the activities by finish time
    sort(activities.begin(), activities.end(), compareFinishTime);

    // take variables to mark the latestFinish and count
    int lastFinishTime = INT_MIN;
    int count = 0;

    cout << "Selected Activities: " << endl;

    //vector<Activity> selected; 
    //if you want to store the activities you selected instead of just printing


    for (Activity activity : activities)
    {
        // For 1 hour gap:
        // current start time must be at least last finish time + 1
        if (activity.start_time >= lastFinishTime + 1)
        {

            //selelected.push_back(activity);
            cout << activity.name << ": "
                 << activity.start_time << " to "
                 << activity.finish_time << endl;

            lastFinishTime = activity.finish_time;
            count++;
        }
    }
    cout << "Total selected items = " << count;
    return 0;
}