#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{

    //converting given adjacency matrix into adjacency list
    vector<vector<pair<int, int>>> adjList(n);

    for (auto time : times)
    {

        int u = time[0];
        int v = time[1];
        int w = time[2];

        //convert 1 index to 0 index
        adjList[u - 1].push_back({w, v - 1});
    }

    vector<int> visited(n, 0);
    vector<int> dist(n, INT_MAX / 2);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[k - 1] = 0;
    pq.push({dist[k - 1], k - 1});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = 1;

        for (auto adj : adjList[u])
        {

            int v = adj.second;
            int w = adj.first;

            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX / 2)
            return -1;
    }

    return dist[n - 1];
}