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

bool checkForCycle(int node, vector<vector<int>> &adj, vector<int> &visited)
{
    queue<pair<int, int>> q;

    visited[node] = 1;
    q.push({node, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }

            else if (it != parent)
                return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>> &adj)
{
    vector<int> visited(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
            if (checkForCycle(i, adj, visited))
                return true;
    }

    return false;
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

    if (isCycle(n, adj))
        cout << "Graph contains cycle" << endl;

    else
        cout << "Graph doesn't contain cycle" << endl;

    return 0;
}