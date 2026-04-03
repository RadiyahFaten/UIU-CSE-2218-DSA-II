#include <iostream>
#include <vector>
using namespace std;

int count_even(vector<int> &arr, int start, int end);

int main()
{
    vector<int> arr = {6, 1, 8, 3, 10, 3, 24, 78, 12, 90};
    int result = count_even(arr, 0, arr.size() - 1);

    cout << "Total even numbers: " << result << endl;

    return 0;
}

int count_even(vector<int> &arr, int start, int end)
{
    // base case
    if (start == end)
    {
        if (arr[start] % 2 == 0)
            return 1;
        else
            return 0;
    }
    int mid = (start + end) / 2;
    int left_count = count_even(arr, start, mid);
    int right_count = count_even(arr, mid + 1, end);

    return left_count + right_count;
}