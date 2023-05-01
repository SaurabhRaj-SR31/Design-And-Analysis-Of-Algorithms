#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;



class graph
{
public:
    

    void addEdge(unordered_map<int, list<int>> &adj,int u, int v, bool direction)
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
};

int main()
{
    graph g;
    unordered_map<int, list<int>> adj;
    int n, m, a, b;
    cout << "enter the no. of vertices:" << endl;
    cin >> n;

    cout << "enter the no. of edges:" << endl;
    cin >> m;

    cout << "enter the edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addEdge(adj,a, b, 0);
    }

    g.printlist(adj);

    return 0;
}