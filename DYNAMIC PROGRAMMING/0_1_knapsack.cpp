#include <iostream>
#include <vector>

using namespace std;

int knapsack_0_1(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    // base case
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0; // when the capacity is zero, no max profit
    }

    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = 0; // for zero iteams, no max profit
    }

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; i <= W; i++)
        {
            if (wt[i] <= W)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i] + val[i]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    vector<int> wt(n + 1);
    vector<int> val(n + 1);

    wt[0] = 0;
    val[0] = 0;

    cout << "Enter the weight of items: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter the value of items: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    int maxProfit = knapsack_0_1(wt, val, n, W );

    cout << "Maximum value that can be obtained = " << maxProfit << endl;
}
