#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int totalViolations(vector<int> &arr, int start, int end);
int violationCount(vector<int> &arr, int start, int end, int mid);

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

    cout << "Total number of violations: " << totalViolations(arr, 0, n) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int totalViolations(vector<int> &arr, int start, int end)
{
    if (start == end)
        return 0;

    int mid = (start + end) / 2;
    int left = totalViolations(arr, start, mid);
    int right = totalViolations(arr, mid + 1, end);
    int merge = violationCount(arr, start, end, mid);

    return left + right + merge;
}

int violationCount(vector<int> &arr, int start, int end, int mid)
{
    int count = 0;
    int i = start;
    int j = mid + 1;

    vector<int> merged;

    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            count += (mid - i) + 1;
            merged.push_back(arr[j]);
            j++;
        }
        else
        {
            merged.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        merged.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        merged.push_back(arr[j]);
        j++;
    }

    for (int i = start, j = 0; i <= end; i++, j++)
    {
        arr[i] = merged[j];
    }

    return count;
}