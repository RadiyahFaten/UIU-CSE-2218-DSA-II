#include <iostream>
#include <vector>
using namespace std;

int knapsack_memo(int W, int n, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp);

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

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    int maxProfit = knapsack_memo(W, n, wt, val, dp);

    cout << "Maximum value that can be obtained = " << maxProfit << endl;
}

int knapsack_memo(int W, int n, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    //base case
    if(n == 0  || W == 0) 
        return 0;
    if(dp[n][W] != -1) 
        return dp[n][W];
    
    if(wt[n] <= W) {
        dp[n][W] = max(val[n] + knapsack_memo(W - wt[n], n - 1, wt, val, dp), 
                        knapsack_memo(W, n - 1, wt, val, dp));
    }

    else {
        dp[n][W] = knapsack_memo(W, n - 1, wt, val, dp);
    }

    return dp[n][W];

}



int knapSackDP(int W, vector<int>& wt, vector<int>& val, int n) {
    
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    

    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= n; i++) {           
        for (int w = 0; w <= W; w++) {
            if (wt[i] <= w) {
               
                dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}