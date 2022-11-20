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

    void BFSUtil(int src, vector<bool> &visited)
    {
        queue<int> q;
        q.push(src);

        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto x : adj[node])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    void BFS(int src)
    {
        vector<bool> visited(V, false);

        BFSUtil(src, visited);
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

    g.BFS(source);

    return 0;
}