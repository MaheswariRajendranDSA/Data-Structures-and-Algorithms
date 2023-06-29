#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int>temp;
        int u, v;
        cin>>u>>v;
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
    }
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    int dist[n];
    for(int i=0;i<n;i++)
    dist[i]=1e9;
    int src=0;
    dist[src]=0;
    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(dist[node]+1 < dist[it])
            dist[it] = dist[node]+1;
            q.push(it);
        }
    }
    vector<int> ans(n, -1);
    for(int i=0;i<n;i++)
    {
        if(dist[i]!=1e9)
        ans[i]=dist[i];
    }
    for(auto it : ans)
    cout<<it<<" ";
    return 0;
}
/*
IP
9 10
0 1
0 3
3 4
4 5
5 6
1 2
2 6
6 7
7 8
6 8
OP
0 1 2 1 2 3 3 4 4
*/