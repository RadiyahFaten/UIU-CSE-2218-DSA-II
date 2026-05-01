#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> r = {10000, 20000, 30000};
    vector<int> v = {10000, 10000};

    sort(r.begin(), r.end());
    sort(v.begin(), v.end());

    int count = 0;
    for (int i = 0, j = 0; i < r.size() && j < v.size(); i++, j++)
    {
        if (v[j] >= r[i])
            count++;
    }

    cout << count << endl;
}