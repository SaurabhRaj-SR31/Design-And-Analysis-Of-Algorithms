#include <iostream>
#include <list>
#include <stack>
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

    void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;

        for (auto v : adj[node])
        {
            if (!visited[v])
            {

                dfs(v, adj, visited, s);
            }
        }

        s.push(node);
    }


    void topologicalsort(int v, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &s)
    {
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, s);
            }
        }
          while (s.empty() == false) {
        cout << s.top() << " ";
        s.pop();
    }
    }




};
int main()
{
    graph g;
    int n, m, a, b;
    unordered_map<int, list<int>> adj;
    unordered_map<int, list<int>> transpose;
    stack<int> s;
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
    g.topologicalsort(n,adj,visited,s);


    return 0;
}