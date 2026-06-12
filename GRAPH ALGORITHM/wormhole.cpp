#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c;
    cin >> c;

    while (c)
    {
        c--;

        int n, m; // node and edges
        cin >> n >> m;

        vector<vector<int>> wormholes;

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            wormholes.push_back({u, v, w});
        }

        vector<int> dist(n, INT_MAX / 2);
        dist[0] = 0;

        bool pastCycle = false;

        for (int i = 1; i <= n; i++)
        {
            for (auto wormhole : wormholes)
            {
                int u = wormhole[0];
                int v = wormhole[1];
                int w = wormhole[2];

                if (dist[v] > dist[u] + w)
                {
                    if (i == n)
                    {
                        pastCycle = true;
                        break;
                    }

                    dist[v] = dist[u] + w;
                }
            }

            if (pastCycle)
            {
                break;
            }
        }

        if (pastCycle)
        {
            cout << "possible" << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
    }
}