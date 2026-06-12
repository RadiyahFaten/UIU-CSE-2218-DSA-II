#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    int D;
    cin >> D;

    vector<int> dp(M + 1, INT_MAX / 2); // dp[sum] -> min coins needed to make sum

    dp[0] = 0;

    for (int coin : coins) // do this for each coin
    {
        for (int sum = M; sum >= coin; sum--)
        {
            dp[sum] = min(dp[sum], dp[sum - coin] + 1); // either take the current coin, or keep the previous count
        }
    }

    if (dp[M] <= D)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}