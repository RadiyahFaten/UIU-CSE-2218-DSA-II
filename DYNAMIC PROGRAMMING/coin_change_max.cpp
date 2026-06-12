#include <iostream>
#include <vector>
using namespace std;

int change(int sum, vector<int> &coins)
{

    vector<int> dp(sum + 1, 0);

    dp[0] = 1; // one way to reach sum 0

    for (int coin : coins)
    {
        for (int i = coin; i <= sum; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[sum];
}
