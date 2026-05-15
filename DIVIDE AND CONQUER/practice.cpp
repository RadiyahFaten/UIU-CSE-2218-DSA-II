#include <iostream>
#include <vector>
using namespace std;
vector<int> right_smaller_count(vector<int> &nums, int start, int end);
void mergesort(vector<pair<int, int>> &arr, int start, int end, vector<int> &count);
void merge(vector<pair<int, int>> &arr, int start, int end, int mid, vector<int> &count);
int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = right_smaller_count(nums, 0, nums.size() - 1);
    for (int x : result)
    {
        cout << x << " ";
    }
}

vector<int> right_smaller_count(vector<int> &nums, int start, int end)
{
    vector<pair<int, int>> arr;
    for (int i = 0; i < nums.size(); i++)
    {
        arr.push_back({nums[i], i});
    }

    vector<int> count(nums.size(), 0);
    mergesort(arr, 0, arr.size() - 1, count);
    return count;
}

void mergesort(vector<pair<int, int>> &arr, int start, int end, vector<int> &count)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;
    mergesort(arr, start, mid, count);
    mergesort(arr, mid + 1, end, count);

    merge(arr, start, end, mid, count);
}

void merge(vector<pair<int, int>> &arr, int start, int end, int mid, vector<int> &count)
{

    int i = start;
    int j = mid + 1;

    vector<int> merged;
    int rightCount = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i].first > arr[j].first)
        {
            rightCount++;
            merged.push_back(arr[j].first);
            j++;
        }
        else
        {
            count[arr[i].second] += rightCount;
            merged.push_back(arr[i].first);
            i++;
        }
    }

    while (i <= mid)
    {
        count[arr[i].second] += rightCount;
        merged.push_back(arr[i].first);
        i++;
    }
    while (j <= end)
    {
        merged.push_back(arr[j].first);
        j++;
    }

    for (int i = start, j = 0; i <= end; i++, j++)
    {
        arr[i].first = merged[j];
    }
}