#include<bits/stdc++.h>
using namespace std;
int timer  = 1;

void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int>adj[])
{
    vis[node]  = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child =0;
    for(auto it : adj[node])
    {
        if(it == parent) continue;
        if(vis[it]==0)
        {
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);

            if(low[it]>=tin[node] && parent!=-1)
            mark[node] = 1;
            child++;
        }
        else
        low[node] = min(low[node], tin[it]);
    }
    if(child>1 && parent==-1)
    mark[node] = 1;
}
vector<int> articulationPoint(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
             dfs(0, -1, vis, tin, low,mark,  adj);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(mark[i]==1)
            ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
int main()
{
    int n;
    cin>>n;
     vector<vector<int>> edges;

    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<2;j++)
        {
        int x;
        cin>>x;
        temp.push_back(x);
        }
        edges.push_back(temp);
    }

    vector<int> node = articulationPoint(n, edges);

    for(auto it : node)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}

/*
IP
5
0 1
1 4
2 4
2 3
3 4
OP
1 4
*/