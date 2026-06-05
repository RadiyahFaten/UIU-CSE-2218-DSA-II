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

        adjList[u].push_back({w, v}); // directed graph
    }

    vector<bool> visited(V, 0);
    vector<int> dist(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src;
    cout << "Enter the source node: ";
    cin >> src;

    dist[src] = 0;

    pq.push({dist[src], src});

    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        int u = node.second;
        pq.pop();

        if (visited[u])
            continue; // to avoid processing the same vertex if repeats

        visited[u] = 1;

        for (auto adj : adjList[u])
        {
            int w = adj.first;
            int v = adj.second;

            // relaxation
            if (!visited[v] && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // print distance
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "src to " << i << ": inf" << endl;
        }
        cout << "src to " << i << ": " << dist[i] << endl;
    }
}
