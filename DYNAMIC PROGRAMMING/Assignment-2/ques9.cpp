#include <iostream>
#include <vector>

using namespace std;

int maximumNonAdjacentSum(vector<int> &arr)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (int n : arr)
    {
        temp = max(i + n, j);
        i = j;
        j = temp;
    }
    return j;
}

int main()
{
    int T; // test cases
    cin >> T;
    while (T)
    {
        T--;

        int N;
        cin >> N;

        vector<int> arr(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        cout << maximumNonAdjacentSum(arr) << endl; 
    }
    return 0;