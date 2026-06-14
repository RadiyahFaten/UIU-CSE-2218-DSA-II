#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int row = heights.size();
        int col = heights[0].size();

        int totalNode = row * col;

        vector<vector<pair<int, int>>> adjList(totalNode);

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // converting grid into graph
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int node = i * col + j;

                for (int k = 0; k < 4; k++)
                {
                    int newRow = i + dx[k];
                    int newCol = j + dy[k];

                    if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col)
                    {
                        int newNode = newRow * col + newCol;
                        int weight = abs(heights[i][j] - heights[newRow][newCol]);

                        adjList[node].push_back({weight, newNode});
                    }
                }
            }
        }

        vector<int> dist(totalNode, INT_MAX / 2);
        vector<int> visited(totalNode, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = 1;

            if (u == totalNode - 1)
                return dist[u];

            for (auto adj : adjList[u])
            {
                int w = adj.first;
                int v = adj.second;

                int newEffort = max(dist[u], w);

                if (!visited[v] && newEffort < dist[v])
                {
                    dist[v] = newEffort;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[totalNode - 1];
    }
};