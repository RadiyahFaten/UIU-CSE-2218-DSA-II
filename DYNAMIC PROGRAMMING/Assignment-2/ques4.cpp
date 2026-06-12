// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {

        vector<int> dp(n + 1, 0);

        // base case
        dp[0] = 1; // only one way to reach step 0- do nothing
        dp[1] = 1; // one way to reach step 1- climb 1 step;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2]; // you can climb both one or two stairs.
        }

        return dp[n];
    }
};