#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;



class graph
{
public:
 

    queue<int> q;

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

  

    void bfs(int src,unordered_map<int, list<int>> &adj, unordered_map<int,bool>&visited )
    {
        visited[src] = true;
        q.push(src);

        while (!q.empty())
        {
            int w = q.front();
            q.pop();
            cout << w << " ";
            for(auto v:adj[w])
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

//     int bfsdisconnected(int v,unordered_map<int, list<int>> &adj, unordered_map<int,bool>&visited)
//     {
// int c=0;
//     for(int i=0;i<v;i++)
//     {
//         if (!visited[i])
//             {
//              c++;
//                 bfs(i,adj,visited);
//             }
//     }
// return c;
// }
};

int main()
{
 graph g;
    int n, m, a, b, src;
  
 unordered_map<int, list<int>> adj;
 unordered_map<int,bool>visited;
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


    cout << "enter the source :" << endl;
    cin >> src;
    g.bfs(src,adj,visited);
//    cout<< g.bfsdisconnected(n,adj,visited);
    return 0;
}