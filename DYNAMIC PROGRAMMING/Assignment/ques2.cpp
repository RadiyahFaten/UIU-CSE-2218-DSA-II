// Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

// Note: if no segment can be cut then return 0.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {

        vector<int> dp(n + 1, -1); // initialize -1 as impossible case

        dp[0] = 0; // when length is zero, max num of cut segments is 0

        for (int i = 1; i <= n; i++)
        {

            if (i >= x && dp[i - x] != -1)
            {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }

            if (i >= y && dp[i - y] != -1)
            {
                dp[i] = max(dp[i], dp[i - y] + 1);
            }

            if (i >= z && dp[i - z] != -1)
            {
                dp[i] = max(dp[i], dp[i - z] + 1);
            }
        }

        if (dp[n] == -1)
            return 0;

        return dp[n]; // returning the max num of cut segments for length n
    }
};