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
        // adj[v][u] = w;
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

    void dijkstraUtil(int src)
    {
        // set implementation

        // set<pair<int, int>> st;
        // vector<int> dist(V, INT_MAX);

        // st.insert({0, src});
        // dist[src] = 0;

        // while (!st.empty())
        // {
        //     for (auto it : st)
        //         cout << it.first << " " << it.second << endl;

        //     for (int i = 0; i < V; i++)
        //         cout << dist[i] << " ";

        //     auto p = *(st.begin());
        //     st.erase(st.begin());

        //     int node = p.second;
        //     int nodeDist = p.first;

        //     for (int i = 0; i < V; i++)
        //     {
        //         if (adj[node][i] != 0)
        //         {
        //             if (dist[i] > nodeDist + adj[node][i])
        //             {
        //                 auto f = st.find({dist[i], i});

        //                 if (f != st.end())
        //                     st.erase(f);

        //                 dist[i] = nodeDist + adj[node][i];
        //                 st.insert({dist[i], i});
        //             }
        //         }
        //     }
        // }


        // priority_queue implementation

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int nodeDist = pq.top().first;

            pq.pop();

            for (int i = 0; i < V; i++)
            {
                if (adj[node][i])
                {
                    if (dist[i] > nodeDist + adj[node][i])
                    {
                        dist[i] = nodeDist + adj[node][i];
                        pq.push({dist[i], i});
                    }
                }
            }
        }

        for (int i = 0; i < V; i++)
            cout << i << ": " << dist[i] << endl;
    }

    void dijkstra()
    {
        int src;
        cin >> src;

        dijkstraUtil(src);
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

    g.dijkstra();

    return 0;
}