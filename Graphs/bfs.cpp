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

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = image[i][j];

        int oldColor = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            ans[x][y] = color;

            if (x - 1 >= 0 && ans[x - 1][y] == oldColor)
                q.push({x - 1, y});
            
            if (y - 1 >= 0 && ans[x][y - 1] == oldColor)
                q.push({x, y - 1});
            
            if (x + 1 < m && ans[x + 1][y] == oldColor)
                q.push({x + 1, y});
            
            if (y + 1 < n && ans[x][y + 1] == oldColor) 
                q.push({x, y + 1});

        }

        return ans;
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