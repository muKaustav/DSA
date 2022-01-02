#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    int adj[n + 1][n + 1];

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << "Node " << i << ": ";

        for (int j = 0; j < n + 1; j++)
        {
            if (adj[i][j] == 1)

                cout << "1 ";

            else
                cout << "- ";
        }

        cout << endl;
    }

    return 0;
}