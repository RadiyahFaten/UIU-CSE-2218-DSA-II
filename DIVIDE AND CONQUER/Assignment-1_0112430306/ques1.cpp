#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Result
{
    int sum;
    int start;
    int end;
};

Result maximum_subarray(vector<int> &arr, int start, int end);
Result crossSum(vector<int> &arr, int start, int mid, int end);

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Result answer = maximum_subarray(arr, 0, arr.size() - 1);

    cout << "Sum = " << answer.sum << endl;
    cout << "Start Index = " << answer.start << endl;
    cout << "End Index = " << answer.end << endl;

    return 0;
}

Result maximum_subarray(vector<int> &arr, int start, int end)
{
    if (start == end)
    {
        return {arr[start], start, end};
    }
    int mid = (start + end) / 2;
    Result left = maximum_subarray(arr, start, mid);
    Result right = maximum_subarray(arr, mid + 1, end);

    Result cross = crossSum(arr, start, mid, end);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

Result crossSum(vector<int> &arr, int start, int mid, int end)
{
    int left = INT_MIN;
    int right = INT_MIN;

    int leftIndex = mid;
    int rightIndex = mid + 1;

    int sum = 0;
    for (int i = mid; i >= start; i--)
    {
        sum += arr[i];
        if (sum > left)
        {
            left = sum;
            leftIndex = i;
        }
    }

    sum = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        sum += arr[i];
        if (sum > right)
        {
            right = sum;
            rightIndex = i;
        }
    }

    Result cross;
    cross.sum = left + right;
    cross.start = leftIndex;
    cross.end = rightIndex;

    return cross;
}