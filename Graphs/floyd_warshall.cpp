#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = vector<vector<int>>(V, vector<int>(V, INT_MAX));
    }

    void addDirectedEdge(int u, int v, int w)
    {
        adj[u][v] = w;
    }

    void printAdjMatrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";

            cout << endl;
        }
    }

    void floydWarshall()
    {
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";

            cout << endl;
        }
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g.addDirectedEdge(u, v, w);
    }

    g.printAdjMatrix();
    g.floydWarshall();

    return 0;
}