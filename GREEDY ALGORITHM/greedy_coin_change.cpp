#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> coins = {1, 2, 5, 10, 25};
    int amount = 63;

    sort(coins.begin(), coins.end(), greater<int>());

    cout << "Selected coins: " << endl;

    int coinCount = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            coinCount++;

            cout << coins[i] << endl;
        }
    }
    cout << "Total coin count: " << coinCount << endl;
}