#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            for (auto x : adj[i])
                cout << x << " ";

            cout << endl;
        }
    }

    void DFSUtil(int src, vector<bool> &visited)
    {
        visited[src] = true;

        cout << src << " ";

        for (auto x : adj[src])
            if (!visited[x])
                DFSUtil(x, visited);
    }

    void DFS(int src)
    {
        vector<bool> visited(V, false);

        DFSUtil(src, visited);
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    int source;
    cin >> source;

    g.DFS(source);

    return 0;
}