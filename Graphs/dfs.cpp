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

void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, vector<int> &dfsOfGraph)
{
    dfsOfGraph.push_back(node);
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
            dfs(it, visited, adj, dfsOfGraph);
    }
}

void dfsUtil(int V, vector<vector<int>> &adj, vector<int> &dfsOfGraph)
{
    vector<int> visited(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
            dfs(i, visited, adj, dfsOfGraph);
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

    vector<int> dfsOfGraph;
    dfsUtil(n, adj, dfsOfGraph);

    for (auto it : dfsOfGraph)
        cout << it << " ";

    return 0;
}