#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adjList(n + 1);

        for (auto road : roads)
        {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adjList[u].push_back({w, v});
            adjList[v].push_back({w, u});
        }

        vector<int> visited(n + 1, 0);
        queue<int> q;

        int ans = INT_MAX;

        q.push(1);
        visited[1] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto adj : adjList[u])
            {
                int w = adj.first;
                int v = adj.second;

                ans = min(ans, w);

                if (!visited[v])
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};