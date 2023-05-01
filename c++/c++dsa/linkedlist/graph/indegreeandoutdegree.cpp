#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph{

public:

void addEdge(unordered_map<int,list<int>> &adj,vector<int> &dat,int u,int v,bool direction)
{
    adj[u].push_back(v);
    dat[v]++;
    if(direction==0)
    {
    adj[v].push_back(u);
    dat[v]++;

    }
}
void printlist(unordered_map<int,list<int>> &adj)
{
    for(auto i:adj)
    {
        cout<<i.first<<"->";
        for(auto j:i.second)
        {
             cout<<j<<",";
        }
        cout<<endl;
    }
}

};


int main()
{
    graph g;
int n,m,a,b;
unordered_map<int,list<int>> adj;
vector<int> dat(n,0);
 cout << "enter the no. of vertices:" << endl;
    cin >> n;

    cout << "enter the no. of edges:" << endl;
    cin >> m;

    cout << "enter the edges:" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addEdge(adj,dat,a, b, 1);
    }

    g.printlist(adj);

cout<<"outdegree:"<<endl;
for(int i=0;i<n;i++)
{
   cout<<i<<":"<<adj[i].size()<<endl;
}

cout<<"indegree:"<<endl;
for(int i=0;i<n;i++)
{
   cout<<i<<":"<<dat[i]<<endl;
}

    return 0;
}