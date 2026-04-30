#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int start, int mid, int end)
{
    int count = 0;

    int k = mid + 1;
    for (int i = start; i <= mid; i++)
    {
        while (k <= end && (long long)arr[i] > 2LL * arr[k])
            k++;
        count += (k - (mid + 1));
    }

    vector<int> merged;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            merged.push_back(arr[i]);
            i++;
        }
        else
        {
            merged.push_back(arr[j]);
            j++;
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

int mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return 0;

    int mid = (start + end) / 2;

    int left = mergeSort(arr, start, mid);
    int right = mergeSort(arr, mid + 1, end);
    int cross = merge(arr, start, mid, end);

    return left + right + cross;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << reversePairs(arr) << endl;
}