#include <iostream>
#include <vector>
#include <utility>

using namespace std;
pair<int, int> max_min(vector<int> &arr, int start, int end);
int main()
{
    vector<int> arr = {-1, 1, 3, 4, 2, -5, 14, 3, 22, -2, 4, 5, 13};
    int n = arr.size();
    pair<int, int> result = max_min(arr, 0, n - 1);
    cout << "max: " << result.first << " min: " << result.second << endl;
}

pair<int, int> max_min(vector<int> &arr, int start, int end)
{
    if(start == end) return {arr[start], arr[end]}; //base case
    int mid = (start + end) / 2;

    pair<int, int> left = max_min(arr, start, mid); //returns left max and min
    pair<int, int> right = max_min(arr, mid + 1, end); //returns right max and min

    int maximum = max(left.first, right.first);
    int minimum = min(left.second, right.second);
    return {maximum, minimum};
}