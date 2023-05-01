#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>

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

    void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int src)
    {
        stack<int> s;
        visited[src] = true;
        s.push(src);
       // cout << src << " ";
        while (!s.empty())
        {
            int w = s.top();
            s.pop();
            for (auto v : adj[w])
            {
                if (!visited[v])
                {
                    s.push(v);
                    visited[v] = true;
                    dfs(adj, visited, v);
                }
            }
        }
    }

    int mothervertex(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int v)
    {
        int last;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                last = i;
            }
        }

        dfs(adj, visited, last);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                return -1;
            }
        }
        return last;
    }
};
int main()
{
    graph g;
    int n, m, a, b, src;
    unordered_map<int, list<int>> adj;
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
    cout<<"mother vertex:"<<g.mothervertex(adj,visited,n)<<endl;

    return 0;
}