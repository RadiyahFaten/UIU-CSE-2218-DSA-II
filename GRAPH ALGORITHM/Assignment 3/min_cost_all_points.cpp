
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {

        int n = points.size();
        vector<vector<pair<int, int>>> adjList(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int w = abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]);

                adjList[i].push_back({w, j});
                adjList[j].push_back({w, i});
            }
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> visited(n, 0);
        int cost = 0;

        pq.push({0, 0, -1});

        while (!pq.empty())
        {
            vector<int> current = pq.top();

            int w = current[0];
            int v = current[1];
            int parent = current[2];
        
            pq.pop();

            if (!visited[v])
            {
                cost += w;
                visited[v] = 1;

                for (auto list : adjList[v])
                {
                    pq.push({list.first, list.second, v});
                }
            }
        }

        return cost;
    }
};