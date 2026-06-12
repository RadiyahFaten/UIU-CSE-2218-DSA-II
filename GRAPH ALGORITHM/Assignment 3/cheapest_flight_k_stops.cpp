#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<int> dist(n, INT_MAX / 2);
    dist[src] = 0;

    for (int i = 1; i <= k + 1; i++)
    {

        vector<int> temp = dist;

        for (auto flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            if (temp[v] > dist[u] + w)
            {
                temp[v] = dist[u] + w;
            }
        }

        dist = temp;
    }

    if (dist[dst] == INT_MAX / 2)
        return -1;                                                                                                                                                              

    return dist[dst];
}
