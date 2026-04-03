#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int start, int end);
void quicksort(vector<int> &arr, int start, int end);
int main()
{
    vector<int> arr = {5, 6, 4, 8, 7, 10, 9};
    quicksort(arr, 0, arr.size() - 1);
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

void quicksort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return; // base case- stop when there's one or no element
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);   // recurse the left side of partition
    quicksort(arr, pivot + 1, end); // recurse the right side of partition
}

int partition(vector<int> &arr, int start, int end)
{
    int i = start - 1;
    int pivot = arr[end];

    for (int j = 0; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}