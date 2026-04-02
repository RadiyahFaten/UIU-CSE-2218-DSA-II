#include <iostream>
#include <vector>

using namespace std;

void mergesort(vector<int> &arr, int start, int end);
void merge(vector<int> &arr, int start, int end, int mid);

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
    mergesort(arr, 0, n - 1);

    for (int x : arr)
        cout << x << " ";
}

void mergesort(vector<int> &arr, int start, int end)
{
    if (start == end)
        return; // base case
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);   // left subarray
    mergesort(arr, mid + 1, end); // right subarray
    merge(arr, start, end, mid);  // combine
}

void merge(vector<int> &arr, int start, int end, int mid)
{
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
}
