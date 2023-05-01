#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

void addedge(unordered_map<int, list<pair<int, int>>> &adj, int u, int w, int v)
{
    adj[u].push_back(make_pair(w, v));
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

void makeset(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

int findparent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);
}

void unionset(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findparent(parent, u);
    v = findparent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
       
    }

    else if (rank[v] < rank[u])
    {
        parent[v] = u;
      
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int kruskals(unordered_map<int, list<pair<int, int>>> &adj, vector<int> &parent, vector<int> &rank)
{
   
        int total = 0;
        for (auto i : adj)
        {
            int u = findparent(parent, i.first);
            for (auto j : i.second)
            {
                int wt = j.second;
                int v = findparent(parent, j.first);
                if (u != v)
                {
                    total += wt;
                    cout << u << " " << v << " " << wt << endl;
                    unionset(parent, rank, u, v);
                }
            }
        }
        return total;
    
}
bool compare_pair_second(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
    int main()
    {
        unordered_map<int, list<pair<int, int>>> adj;
        int n, m, a, b, wt;
        cout << "enter no. of nodes:" << endl;
        cin >> n;

        cout << "enter no. of edges:" << endl;
        cin >> m;
        cout << "enter edges:" << endl;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> wt>> b;

            addedge(adj, a, wt, b);
        }
        printlist(adj);
        vector<int> parent(n);
        vector<int> rank(n, 0);
        makeset(parent, rank, n);

vector<pair<int, list<pair<int, int>>>> sorted_vec(adj.begin(), adj.end());
for (auto& p : sorted_vec) {
    p.second.sort(compare_pair_second);
}

// Rebuild map from sorted vector
unordered_map<int, list<pair<int, int>>> sorted_adj(sorted_vec.begin(), sorted_vec.end());

        cout << "minimum cost:" << kruskals(sorted_adj, parent, rank);
        return 0;
    }
    // 0
    // 1
    // 7
    // 0
    // 2
    // 8
    // 1
    // 2
    // 3
    // 1
    // 4
    // 6
    // 2
    // 4
    // 4
    // 2
    // 3
    // 3
    // 3
    // 4
    // 2
    // 3
    // 5
    // 2
    // 5
    // 4
    // 5