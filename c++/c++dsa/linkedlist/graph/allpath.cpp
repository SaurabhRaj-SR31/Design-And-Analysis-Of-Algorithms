#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;
class graph
{

public:
    stack<int> s;

    void addEdge(unordered_map<int, list<int>> &adj, int u, int v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printpaths(vector<vector<int>> &allpath, vector<int> &path)
    {
        for (auto p : allpath)
        {
            for (int i = 0; i < p.size(); i++)
            {
                cout << p[i] << " ";
                if(i<p.size()-1)
                {
                   cout << " ->"; 
                }
            }
        }
        cout << endl;
    }

    // void dfs(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &ans)
    // {
    //     visited[src] = true;
    //     s.push(src);

    //     // cout<< src << " ";
    //     while (!s.empty())
    //     {
    //         int w = s.top();
    //         s.pop();
    //         for (auto v : adj[w])
    //             if (!visited[v])
    //             {
    //                 s.push(v);
    //                 visited[v] = true;
    //                 dfs(v, adj, visited, ans);
    //             }
    //     }
    // }
   vector<vector<int>>  findpaths(int src, int destn, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<vector<int>> &allpath, vector<int> &path)
    {

        visited[src] = true;
        path.push_back(src);
        if (src == destn)
        {
            allpath.push_back(path);
             return allpath;
        }
        else
        {

            for (auto x : adj[src])
            {

                if (!visited[x])
                  return  findpaths(x, destn, adj, visited, allpath, path);
            }
        }

        path.pop_back();
    }
};

int main()
{
    graph g;
    int n, m, a, b, src, destn;

    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> allpath;
    vector<int> path;
    cout << "enter the no. of vertices:" << endl;
    cin >> n;

    cout << "enter the no. of edges:" << endl;
    cin >> m;

    cout << "enter the edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addEdge(adj, a, b, 0);
    }

    cout << "enter the source :" << endl;
    cin >> src;

    cout << "enter the destn :" << endl;
    cin >> destn;

    g.findpaths(src, destn, adj, visited, allpath, path);
    g.printpaths(allpath, path);
    return 0;
}