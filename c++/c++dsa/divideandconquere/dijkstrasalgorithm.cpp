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

void dijkstras(unordered_map<int, list<pair<int, int>>> &adj, int n, int src)
{
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // vector<int> dist(n);
    // for (int i = 0; i < n; i++)
    // {
    //     dist[i] = 1e9;
    // }
    // dist[src] = 0;
    // pq.push(make_pair(0, src));
    // while (!pq.empty())
    // {
    //     int distance = pq.top().first;

    //     int node = pq.top().second;
    //     pq.pop();
    //     for (auto i : adj[node])
    //     {
    //         int adjnode = i.first;
    //         int edgewt = i.second;
    //         if (distance + edgewt < dist[adjnode])
    //         {
    //             dist[adjnode] = distance + edgewt;
    //             pq.push(make_pair(dist[adjnode], adjnode));
    //         }
    //     }
    // }
    // for (auto i : dist)
    // {
    //     cout << i << " ";
    // }

    set<pair<int, int>> st;

    vector<int> dist(n, 1e9);

    dist[src] = 0;
    st.insert(make_pair(0, src));
    while (!st.empty())
    {
        auto i = *(st.begin());
        int distance = i.first;

        int node = i.second;
        st.erase(i);
        for (auto i : adj[node])
        {
            int adjnode = i.first;
            int edgewt = i.second;
            if (distance + edgewt < dist[adjnode])
            {
                auto record=st.find(make_pair(dist[adjnode], adjnode));
                if(record!=st.end())
                {
                    st.erase(record);
                }
                dist[adjnode] = distance + edgewt;
                st.insert(make_pair(dist[adjnode], adjnode));
            }
        }
    }
    for (auto i : dist)
    {
        cout << i << " ";
    }
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

    cout << "enter the source:" << endl;
    cin >> src;
    dijkstras(adj, n, src);
}