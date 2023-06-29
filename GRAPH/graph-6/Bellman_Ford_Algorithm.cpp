#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n, 1e9);
    dist[src] =0;

    for(int i=0;i<n-1;i++)
    {
        for(auto it :edges)
        {
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            if(dist[u]!=1e9 && dist[u]+wt <dist[v])
            {
                dist[v] = dist[u] +wt;
            }
        }
    }

    //N th re;axation of a node to check a negative cycle
    for(auto it :edges)
        {
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            if(dist[u]!=1e9 && dist[u]+wt <dist[v])
            {
                return {-1};
            }
        }
        return dist;
}

int main()
{
    int n, s, m;
    cin>>n>>s>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int j=0;j<3;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }
    vector<int> dista = bellmanFord(n, s, edges);
    for(int it : dista)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}

/*
IP
6 0 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
OP
0 5 3 3 1 2
Negative cycle
IP
3 0 3
3 1 2
1 2 -2
2 3 -2
OP
-1
*/