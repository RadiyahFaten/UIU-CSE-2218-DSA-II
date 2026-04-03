#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct MaxMin
{
    int maximum;
    int minimum;
    int second_maximum;
    int second_minimum;
};

MaxMin second_max_min(vector<int> &arr, int start, int end)
{
    if (start == end)
        return {arr[start], arr[start], INT_MIN, INT_MAX};
    
    int mid = (start + end) / 2;
    MaxMin left = second_max_min(arr, start, mid);
    MaxMin right = second_max_min(arr, mid + 1, end);

    MaxMin result;
    
    //maximum
    if(left.maximum >= right.maximum) {
        result.maximum = left.maximum;
        result.second_maximum = max(right.maximum, left.second_maximum);
    }
    else {
        result.maximum = right.maximum;
        result.second_maximum = max(right.second_maximum, left.maximum);
    }

    //minimum
    if(left.minimum <= right.minimum) {
        result.minimum = left.minimum;
        result.second_minimum = min(left.second_minimum, right.minimum);
    }
    else {
        result.minimum = right.minimum;
        result.second_minimum = min(right.second_minimum, left.minimum);
    }

    return result;
}

int main () {
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -22, 4, 5, 33, -53};
    MaxMin res = second_max_min(arr, 0, arr.size() - 1);
    cout << "max: " << res.maximum << " min: " << res.minimum << endl;
    cout << "2nd max: " << res.second_maximum << " 2nd min: " << res.second_minimum << endl;
}