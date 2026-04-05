#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> right_smaller_element(vector<int> &nums, int start, int end);
void mergesort(vector<pair<int, int>> &arr, int start, int end, vector<int> &count);
void merge(vector<pair<int, int>> &arr, int start, int mid, int end, vector<int> &count);

int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = right_smaller_element(nums, 0, nums.size() - 1);
    for (int x : result)
    {
        cout << x << " ";
    }
}

vector<int> right_smaller_element(vector<int> &nums, int start, int end)
{
    int n = nums.size();
    vector<int> count(n, 0);
    vector<pair<int, int>> elements_index;
    for (int i = 0; i < n; i++)
        elements_index.push_back({nums[i], i});
    mergesort(elements_index, start, end, count);
    return count;
}

void mergesort(vector<pair<int, int>> &arr, int start, int end, vector<int> &count)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;

    mergesort(arr, start, mid, count);
    mergesort(arr, mid + 1, end, count);

    merge(arr, start, mid, end, count);
}

void merge(vector<pair<int, int>> &arr, int start, int mid, int end, vector<int> &count)
{
    int i = start;
    int j = mid + 1;

    vector<pair<int, int>> merged;
    int rightCount = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i].first > arr[j].first)
        {
            rightCount++;
            merged.push_back(arr[j]);
            j++;
        }
        else
        {
            count[arr[i].second] += rightCount;
            merged.push_back(arr[i]);
            i++;
        }
    }
    while (i <= mid)
    {
        count[arr[i].second] += rightCount;
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