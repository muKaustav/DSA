#include <bits/stdc++.h>
using namespace std;

void adjacencyList(vector<int> adj[], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    adjacencyList(adj, n, m);

    for (int i = 0; i < n + 1; i++)
    {
        cout << "Node " << i << ": ";

        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }

    return 0;
}