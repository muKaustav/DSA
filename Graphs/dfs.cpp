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

        void FloodFillUtil(vector<vector<int>> &image, int x, int y, int color, int oldColor)
    {
        if (x < 0 || y < 0 || x >= image.size() || y >= image[0].size())
            return;

        if (image[x][y] != oldColor || image[x][y] == color)
            return;

        image[x][y] = color;

        FloodFillUtil(image, x - 1, y, color, oldColor);
        FloodFillUtil(image, x, y - 1, color, oldColor);
        FloodFillUtil(image, x + 1, y, color, oldColor);
        FloodFillUtil(image, x, y + 1, color, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = image[i][j];

        FloodFillUtil(ans, sr, sc, color, oldColor);

        return ans;
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