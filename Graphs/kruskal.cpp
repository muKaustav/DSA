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
        adj = vector<vector<int>>(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        adj[v][u] = w;
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

        g.addEdge(u, v, w);
    }

    g.printAdjMatrix();

    return 0;
}