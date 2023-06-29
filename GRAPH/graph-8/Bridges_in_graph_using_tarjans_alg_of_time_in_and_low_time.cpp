#include<bits/stdc++.h>
using namespace std;
int timer  = 1;

void dfs(int node, int parent, vector<int> &vis, vector<int>adj[], int tin[], int low[], vector<vector<int>> &bridges)
{
    vis[node]  = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it : adj[node])
    {
        if(it == parent) continue;
        if(vis[it]==0)
        {
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);

            if(low[it]>tin[node])
            bridges.push_back({it, node});
        }
        else
        low[node] = min(low[node], low[it]);
    }
}
  vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
int main()
{
    int n;
    cin>>n;
     vector<vector<int>> connections;

    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<2;j++)
        {
        int x;
        cin>>x;
        temp.push_back(x);
        }
        connections.push_back(temp);
    }

    vector<vector<int>> bridges = criticalConnections(n, connections);

    for(auto it : bridges)
    {
        cout<<"["<<it[0]<<","<<it[1]<<"]";
    }
    cout<<"\n";
    return 0;
}

/*
IP
4
0 1
1 2
2 0
1 3
OP
[3,1]
*/