#include <iostream>
#include <vector>
using namespace std;
class graph
{

public:
    void addEdge(vector<int> adj[], int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }
    void printlist(vector<int> adj[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout<<i<<"->";
            for (auto x : adj[i])
            {
                cout << x << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    graph g;
    int n, m, a, b;
    bool direction;
    cout << "enter the type of graph:" << endl;
    cin >> direction;
    cout << "enter the no. of vertices:" << endl;
    cin >> n;
    vector<int> adj[n];
    cout << "enter the no. of edges:" << endl;
    cin >> m;

    cout << "enter the edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addEdge(adj, a, b, 0);
    }

    g.printlist(adj, n);

    return 0;
}