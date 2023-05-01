#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
void addedge(unordered_map<int, list<pair<int, int>>> &adj, int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void printlist(unordered_map<int, list<pair<int, int>>> &adj)
{
    for (auto i : adj)
    {
        cout << i.first << "->";
        for (auto j : i.second)
        {
            cout << "{" << j.first << "," << j.second << "} ";
        }
        cout << endl;
    }
}

void bellmenford(unordered_map<int, list<pair<int, int>>> &adj, int src, int dest, int n, int m)
{
    vector<int> dist(n, 1e9);
    int u, v, wt;
    dist[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto i : adj)
        {
            u = i.first;
            for (auto j : i.second)
            {
                v = j.first;
                wt = j.second;
                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    dist[v] = wt + dist[u];
                }
            }
        }
    }
    bool flag = false;
    for (auto i : adj)
    {
        u = i.first;
        for (auto j : i.second)
        {
            v = j.first;
            wt = j.second;
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                flag = true;
            }
        }
    }
    if (flag == false)
    {
        for (auto i : dist)
            cout << i << " ";
    }
    cout << endl;
    cout << dist[dest];
}

int main()
{
    int n, m, a, node, wt, src;
    unordered_map<int, list<pair<int, int>>> adj;
    cout << "enter the no. of vertices:" << endl;
    cin >> n;

    cout << "enter the no. of edges:" << endl;
    cin >> m;

    cout << "enter the edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> node >> wt;
        addedge(adj, a, node, wt);
    }
    printlist(adj);
    int dest;
    cout << "enter the source:" << endl;
    cin >> src;
    cout << "enter the source:" << endl;
    cin >> dest;
    bellmenford(adj, src, dest, n, m);
}