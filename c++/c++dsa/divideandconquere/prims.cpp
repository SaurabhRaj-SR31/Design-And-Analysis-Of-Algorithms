#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

void addedge(unordered_map<int, list<pair<int, int>>> &adj, int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
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

void prims(unordered_map<int, list<pair<int, int>>> &adj, int src, int n, vector<int> &key, vector<int> &mst, vector<int> &parent)
{
    for (int i = 0; i < n; i++)
    {
        key[i] = 1e9;
        parent[i] = -1;
        mst[i] = 0;
    }
    key[src] = 0;
    parent[src] = -1;
    int min = INT_MAX;
    int u;

    for (int i = 1; i <=n; i++)
    {
        if (key[i] < min && mst[i] == 0)
        {
            min = key[i];
            u = i;
        }
    }
    mst[u] = 1;
    for (auto v : adj[u])
    {
        int node = v.first;
        int wt = v.second;
        if (mst[node] == 0 && wt < key[node])
        {
            parent[node] = u;
            key[node] = wt;
        }
    }

    cout << "parent\tnode\twt:" << endl;
    int sum = 0;
    for (int i = 2; i <=n; i++)
    {
        sum += key[i];
        cout << parent[i] << "\t" << i << "\t" << key[i] << endl;
    }
    cout << "minimum cost:" << sum << endl;
}

int main()
{
    int n, m, a, node, wt, src;
    unordered_map<int, list<pair<int, int>>> adj;
    vector<int> key(n + 1);
    vector<int> mst(n + 1);
    vector<int> parent(n + 1);

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

    cout << "enter the source:" << endl;
    cin >> src;
    prims(adj, src, n, key, mst, parent);
}