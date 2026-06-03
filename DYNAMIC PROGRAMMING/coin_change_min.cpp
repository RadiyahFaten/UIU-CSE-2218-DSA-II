#include <iostream>
#include <vector>
using namespace std;

int coinChangeMin_memo(vector<int> &coins, int sum, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    if (sum == 0)
        return 0;

    if (n == 0 && sum > 0)
        return INT_MAX - 1;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (coins[n - 1] <= sum)
    {
        dp[n][sum] = min(1 + coinChangeMin_memo(coins, sum - coins[n - 1], n), coinChangeMin_memo(coins, sum, n - 1));
    }

    else
    {
        dp[n][sum] = coinChangeMin_memo(coins, sum, n - 1);
    }

    return dp[n][sum];
}

int coinChangeMin_tabular(vector<int> &coins, int sum, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    // Part-1: Initialization (base cases, first coin case)
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // when sum = 0 -> no sum exists
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            // when there are no coins -> no sum can be achieved (impossible)
            else if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }

            // when there is only one coin
            else if (i == 1)
            {
                if (j % coins[i - 1] == 0) // if the coin is divisible by the sum, we can take the coin
                {
                    dp[i][j] = j / coins[i - 1]; // number of coins
                }
                else
                {
                    dp[i][j] = INT_MAX - 1; // not possible
                }
            }
            else
            {
                dp[i][j] = INT_MAX - 1; // placeholder(for comparison later)
            }
        }
    }

    // for multiple coins
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    vector<int> coins(n);

    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int sum;
    cout << "Enter the sum = ";
    cin >> sum;

    int result = coinChangeMin_tabular(coins, sum, n);

    if (result >= INT_MAX - 1)
        cout << "Impossible to make the sum";
    else
        cout << result << endl;
}
