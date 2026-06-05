#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int V, E;
    cout << "Enter the number of nodes: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // adjacency matrix
    vector<vector<int>> edges;

    cout << "Enter the nodes connected with the edge and edge weight: ";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    vector<int> distance(V, INT_MAX / 2);
    distance[src] = 0;

    for (int i = 1; i <= V; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (distance[u] != INT_MAX / 2 && distance[v] > distance[u] + w)
            {
                if (i == V)
                {
                    cout << "negative cycles exist";
                }
                distance[v] = distance[u] + w;
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << src << " to " << i << ": " << distance[i] << endl;
}