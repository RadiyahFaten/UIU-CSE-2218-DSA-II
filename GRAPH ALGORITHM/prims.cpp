#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int V, E;
    cout << "Enter the number of nodes: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // adjacency list for the graph
    vector<vector<pair<int, int>>> adjList(V);

    cout << "Enter the nodes connected with the edge and edge weight: ";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u}); // undirected graph
    }

    vector<bool> visited(V, 0);

    // min heap that pops the min weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // first node weight = 0 and node is also 0
    pq.push({0, 0});

    int cost = 0;

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();

        int w = current.first;
        int v = current.second;

        pq.pop();

        if (!visited[v])
        {
            visited[v] = 1;
            cost += w;

            for (auto adj : adjList[v])
            {
                pq.push({adj.first, adj.second});
            }
        }
    }

    cout << "Minimum cost for MST: " << cost << endl;
}