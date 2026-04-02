#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maximum_subarray_sum(vector<int> &arr, int start, int end);
int cross_sum(vector<int> &arr, int start, int end, int mid);

int main()
{
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int n = arr.size() - 1;
    int result = maximum_subarray_sum(arr, 0, n);
    cout << result << endl;
}

int maximum_subarray_sum(vector<int> &arr, int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int left = maximum_subarray_sum(arr, start, mid);
    int right = maximum_subarray_sum(arr, mid + 1, end);
    int cross = cross_sum(arr, start, end, mid);

    return max(max(left, right), cross);
}

int cross_sum(vector<int> &arr, int start, int end, int mid)
{
    int left = INT_MIN;
    int right = INT_MIN;

    int sum = 0;
    for (int i = mid; i >= start; i--)
    {
        sum += arr[i];
        left = max(sum, left);
    }
    sum = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        sum += arr[i];
        right = max(sum, right);
    }

    return left + right;
}