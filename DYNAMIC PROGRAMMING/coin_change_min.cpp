#include <iostream>
#include <vector>
using namespace std;

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

    int result = coinChangeMin(coins, sum);

    if (result >= INT_MAX - 1)
        cout << "Impossible to make the sum";
    else
        cout << result << endl;
}

int coinChangeMin(vector<int> &coins, int sum)
{
    vector<int> dp(sum + 1, INT_MAX / 2);

    // base case
    dp[0] = 0; // no coins for 0 sum

    for (int i = 1; i <= sum; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
}