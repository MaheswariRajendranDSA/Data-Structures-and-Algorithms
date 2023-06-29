#include<bits/stdc++.h>
using namespace std;

void topoSort(int vis[], vector<pair<int,int>>adj[], int node, stack<int>&st)
{
    vis[node]=1;
    for(auto it : adj[node])
    {
        int v = it.first;
        if(!vis[v])
        {
            topoSort(vis, adj, v, st);
        }
    }
    st.push(node);
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>edge;
    for(int i=0;i<m;i++)
    {
        vector<int>temp;
        for(int j=0;j<3;j++)
        {
        int x;
        cin>>x;
        temp.push_back(x);
        }
        edge.push_back(temp);
    }
    vector<pair<int, int>> adj[n];

    for(int i=0;i<m;i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        adj[u].push_back({v, wt});
    }
    int vis[n]={0};
    stack <int> st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topoSort(vis, adj, i, st);
        }
    }
    vector<int> dist(n);
    for(int i=0;i<n;i++)
    dist[i]=1e9;
    //int dist = {1e9};
    int src = 0;
    dist[src] = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        for(auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if(dist[node]+wt < dist[v])
            {
                dist[v] = dist[node]+wt;
            }
        }
    }
    for(auto it : dist)
    cout<<it<<" ";
    return 0;
}

/*
IP
6 7
0 1 2
0 4 1
4 5 4
4 2 2
1 2 3
2 3 6
5 3 1
OP
0 2 3 6 1 5
*/