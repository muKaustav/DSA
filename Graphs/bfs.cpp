#include <bits/stdc++.h>
using namespace std;

void adjacencyList(vector<vector<int>> &adj, int m)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int V, vector<vector<int>> &adj, vector<int> &bfsOfGraph)
{
    vector<int> visited(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);

            visited[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                bfsOfGraph.push_back(node);

                for (auto it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m, i = 0;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    adjacencyList(adj, m);

    for (auto it : adj)
    {
        cout << "Node " << i << ": ";

        for (auto it2 : it)
            cout << it2 << " ";

        cout << endl;

        i++;
    }

    vector<int> bfsOfGraph;
    bfs(n, adj, bfsOfGraph);

    for (auto it : bfsOfGraph)
        cout << it << " ";

    return 0;
}