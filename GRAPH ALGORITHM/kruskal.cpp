#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find my path compression
int Find(int node, vector<int> &parent)
{
    if (parent[node] == -1)
        return node;

    return parent[node] = Find(parent[node], parent);
}

//Union by size
void Union(int u, int v, vector<int> &parent, vector<int> &size)
{
    int parent_U = Find(u, parent);
    int parent_V = Find(v, parent);

    if (parent_U == parent_V)
        return;

    if (size[u] > size[v])
    {
        parent[v] = parent_U; // u becomes parent of v
        size[u] += size[v];   // everything under v goes under u
    }
    else
    {
        parent[u] = parent_V; // v becomes parent of u
        size[v] += size[u];   // everything under u goes under v
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of nodes and edges:";
    cin >> V >> E;

    // Take input for the edges- adjacency matrix
    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, w; // the nodes and the weight of the edge

        cin >> u >> v >> w;
        edges.push_back({w, u, v}); // weight first for sorting
    }

    vector<int> parent(V, -1); // parent of each node
    vector<int> size(V, 1);    // size of each component

    int mstCount = 0;  // counts the edge weight for MST
    int edgeCount = 0; // counts the number of edges to check for MST

    sort(edges.begin(), edges.end()); // ascending sort of weight for MST

    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (Find(u, parent) != Find(v, parent))
        {
            Union(u, v, parent, size);

            mstCount += w;
            edgeCount++;

            cout << u << "---" << v << endl;
        }

        if (edgeCount == V - 1)
            break;
    }

    cout << "Minimum weight = " << mstCount << endl;
}