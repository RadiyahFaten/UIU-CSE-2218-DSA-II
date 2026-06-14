#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        int n = passingFees.size();

        vector<vector<pair<int, int>>> adjList(n);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adjList[u].push_back({time, v});
            adjList[v].push_back({time, u});
        }

        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX / 2));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dp[0][0] = passingFees[0];

        // cost, time, node
        pq.push({passingFees[0], 0, 0});

        while (!pq.empty())
        {
            vector<int> current = pq.top();
            pq.pop();

            int cost = current[0];
            int time = current[1];
            int u = current[2];

            if (u == n - 1)
                return cost;

            if (cost > dp[u][time])
                continue;

            for (auto adj : adjList[u])
            {
                int edgeTime = adj.first;
                int v = adj.second;

                int newTime = time + edgeTime;

                if (newTime <= maxTime)
                {
                    int newCost = cost + passingFees[v];

                    if (newCost < dp[v][newTime])
                    {
                        dp[v][newTime] = newCost;
                        pq.push({newCost, newTime, v});
                    }
                }
            }
        }

        return -1;
    }
};