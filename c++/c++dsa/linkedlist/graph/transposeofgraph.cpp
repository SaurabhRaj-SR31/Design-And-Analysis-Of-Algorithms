#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class graph
{
public:
    void addEdge(unordered_map<int, list<int>> &adj, int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printlist(unordered_map<int, list<int>> &adj)
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
    void transpose(unordered_map<int, list<int>> &transpose, unordered_map<int, list<int>> &adj, int v)
    {
        for (int i = 0; i < v; i++)
        {
            for (auto x : adj[i])
            {
                transpose[x].push_back(i);
            }
        }
    }
};

int main()
{
    graph g;
    int n, m, a, b;
    unordered_map<int, list<int>> adj;
    unordered_map<int, list<int>> transpose;

    unordered_map<int, bool> visited;

    cout << "enter the no. of vertices:" << endl;
    cin >> n;

    cout << "enter the no. of edges:" << endl;
    cin >> m;

    cout << "enter the edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addEdge(adj, a, b, 1);
    }

    g.printlist(adj);
    g.transpose(transpose, adj, n);
cout<<endl;
    g.printlist(transpose);

    return 0;
}