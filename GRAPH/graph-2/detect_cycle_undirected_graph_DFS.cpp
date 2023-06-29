#include<bits/stdc++.h>
using namespace std;

 bool checkForCycle_dfs(int s, int parent, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        visited[s] = true;

        for(auto it : adj[s])
        {
            if(!visited[it])
            {
                if(checkForCycle_dfs(it, s, V, adj, visited)==true)
                return true;
            }
            else{
                if(visited[s] && parent != it)
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle_dfs(i, -1, V, adj, vis))
                    return true;
            }
        }
        return false;
    }

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>adjlist[n];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int ans=0;
    ans = isCycle(n, adjlist);
    if(ans==0)
    cout<<"false";
    else
    cout<<"true";
   return 0;
}

/*
3 3
0 1
1 2
2 0
OP
true
IP
4 3
0 1
1 2
2 3
OP
false
*/