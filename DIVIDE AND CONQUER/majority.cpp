#include <iostream>
#include <vector>
using namespace std;

int countMajority(vector<int> &arr, int start, int end, int majority)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == majority)
            count++;
    }
    return count;
}

int majority(vector<int> &arr, int start, int end)
{
    if (start == end)
        return arr[start]; // base case
    int mid = (start + end) / 2;
    int leftMajority = majority(arr, start, mid);
    int rightMajority = majority(arr, mid + 1, end);

    // if left and right majority is the same element
    if (leftMajority == rightMajority)
        return leftMajority;

    // if not same element, must count both occurences
    int leftCount = countMajority(arr, start, end, leftMajority);
    int rightCount = countMajority(arr, start, end, rightMajority);

    return (leftCount >= rightCount) ? leftMajority : rightMajority;
}

int main()
{
    vector<int> arr = {4, 1, 4, 2, 4, 4, 3, 4, 4};
    cout << "Majority Number: " << majority(arr, 0, arr.size() - 1) << endl;
}